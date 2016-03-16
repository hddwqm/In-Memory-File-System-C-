
#include"prjheader.h"


class FileSystem {
	folder root;
public:
	FileSystem() :root(std::string("")) {}

	/*Navigate to the specified dictionary, returns the ptr of the folder and the name of the last member in the path
	  If mode is specified as "RW", it will create the folder that is not exist.*/
	std::tuple<fs_base*,  std::string> get_target(std::string path, std::string mode = "R") {
		//get path
		std::vector<std::string> folder_path = split(path, '/');		//split input into separate folder name
		fs_base* it = &root;
		if (folder_path.size() == 0) {
			return std::make_tuple(it, "");
		}
		int index = 0;
		std::string current_path = "";			//use this to store the current path
		for (index = 0;index < folder_path.size()-1;index++) {
			current_path = current_path + "/" + folder_path[index];
			//Dictionary exists, continue
			if (it->get_member(folder_path[index]) != nullptr) {
				it = it->get_member(folder_path[index]);
			}
			//Dictionary doesn't exist but mode is "RW", will create
			else if (mode == "RW" && it->get_type()==fs_base::fs_type::FOLDER) {
				class folder* temp = new class folder(folder_path[index]);
				it->insert_member(folder_path[index], temp);
				it = temp;
			}
			else {											//return error if there is no such name or if the name represents a file
				return std::make_tuple(nullptr,current_path);
			}
		}
		//Returns <dictionary pointor, target name>
		return std::make_tuple(it,folder_path[index]);
	}

	//Ls
	std::vector<std::string> Ls(const std::string& path) {
		//get path
		std::tuple<fs_base*, std::string> target = get_target(path);
		fs_base* it = std::get<0>(target);
		std::string target_name = std::get<1>(target);
		//If input path is root
		if (target_name == "") {
			return it->get_content();
		}
		//If the dictionary doesn't exist, return an error
		if (it == nullptr || it->get_member(target_name)==nullptr) {
			std::vector<std::string> return_val;
			return_val.push_back("Error: No such dictionary: "+path);
			return return_val;
		}
		it = it->get_member(target_name);
		//If find a file, return error
		if (it->get_type() == fs_base::fs_type::FILE) {
			std::vector<std::string> return_val;
			return_val.push_back("Error: No such dictionary: " + path);
			return return_val;
		}
		//Returns the content of the dictionary
		return it->get_content();
	}

	void MkdirP(const std::string& path) {
		std::tuple<fs_base*, std::string> target = get_target(path,"RW");
		fs_base* it = std::get<0>(target);
		std::string target_name = std::get<1>(target);
		//Failed to create dictionary
		if (it == nullptr) {
			std::cout << "Failed to create dictionary " << target_name << ", it is a file's name." << std::endl;
			return;
		}
		//Create
		if (it->get_member(target_name) == nullptr) {
			class folder* temp = new class folder(target_name);
			it->insert_member(target_name, temp);
			return;
		}
		//Failed to create dictionary
		if (it->get_member(target_name)->get_type()== fs_base::fs_type::FILE) {
			std::cout << "Failed to create dictionary " << path << ", it is a file's name." << std::endl;
			return;
		}
	}

	void AddFileWithContent(const std::string& path, const std::string& content) {
		//First check if the path represents a dictionary
		std::size_t found = path.find_last_of("/");
		if (found == path.size()) {
			std::cout << "Error: " << path << " is not a file." << std::endl;
		}

		std::tuple<fs_base*, std::string> target = get_target(path, "RW");
		fs_base* it = std::get<0>(target);
		std::string target_name = std::get<1>(target);
		if (it == nullptr) {
			std::cout << "Failed to create dictionary " << target_name << ", it is a file's name." << std::endl;
			return;
		}
		//Create file
		if (it->get_member(target_name) == nullptr) {
			class file* temp = new class file(target_name, content);
			it->insert_member(target_name, temp);
			return;
		}
		//File name already exist
		if (it->get_member(target_name) != nullptr) {
			std::cout << "Error: " << path << " already exits." << std::endl;
			return;
		}
	}

	std::string GetFileContent(const std::string& path) {
		std::tuple<fs_base*, std::string> target = get_target(path);
		fs_base* it = std::get<0>(target);
		std::string target_name = std::get<1>(target);
		//If the dictionary doesn't exist, return an error
		if (it == nullptr) {
			return ("Error: No such dictionary: " + target_name);
		}
		it = it->get_member(target_name);
		//If the file doesn't exist, return an error
		if (it == nullptr) {
			return ("Error: No such file: " + path);
		}
		if (it->get_type() == fs_base::fs_type::FOLDER) {
			return "Error: Found a dictionary instead of file.";
		}
		//Return the content
		return it->get_content()[0];
	}
};