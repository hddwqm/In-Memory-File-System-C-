
#include"prjheader.h"


class FileSystem {
	folder root;
public:
	FileSystem() :root(std::string("")) {
	}

	//Ls
	std::vector<std::string> Ls(const std::string& path) {
		//get path
		std::vector<std::string> folder_path = split(path, '/');		//split input into separate folder name
		fs_base* it = &root;
		for (int index = 0;index < folder_path.size();index++) {
			if (it->get_member(folder_path[index]) != nullptr) {
				it = it->get_member(folder_path[index]);
			}
			else {											//return error if there is no such name or if the name represents a file
				std::vector<std::string> return_val;
				return_val.push_back("Error: Folder not found!");
				return return_val;
			}
		}
		if (it->get_type() == fs_base::fs_type::FILE) {
			std::vector<std::string> return_val;
			return_val.push_back("Error: Found a file instead of folder.");
			return return_val;
		}
		return it->get_content();
	}

	void MkdirP(const std::string& dir_path) {
		std::vector<std::string> folder_path = split(dir_path, '/');
		fs_base* it = &root;
		std::string current_path = "";
		for (int index = 0;index < folder_path.size();index++) {
			current_path = current_path + "/" + folder_path[index];
			//If the folder doesn't exist, create it. If the folder name specified is already used as a file name, return with an error message.
			if (it->get_member(folder_path[index]) != nullptr) {
				it = it->get_member(folder_path[index]);
			}
			else if (it->get_type() == fs_base::fs_type::FILE) {
				std::cout << "Failed to create folder " << current_path << ", it is a file's name." << std::endl;
				return;			
			}
			else {
				class folder* temp = new class folder(folder_path[index]);
				it->insert_member(folder_path[index], temp);
				it = temp;
			}
		}
	}

	void AddFileWithContent(const std::string& file_path, const std::string& content) {
		std::size_t found = file_path.find_last_of("/");
		if (found == file_path.size()) {
			std::cout << "Error: " << file_path << " is not a file." << std::endl;
		}
		std::vector<std::string> folder_path = split(file_path, '/');
		fs_base* it = &root;
		std::string current_path = "";
		int index = 0;
		for (index = 0;index < folder_path.size()-1;index++) {
			current_path = current_path + "/" + folder_path[index];
			//If the folder doesn't exist, create it. If the folder name specified is already used as a file name, return with an error message.
			if (it->get_member(folder_path[index]) != nullptr) {
				it = it->get_member(folder_path[index]);
			}
			else if (it->get_type() == fs_base::fs_type::FILE) {
				std::cout << "Failed to create folder " << current_path << ", it is a file's name." << std::endl;
				return;
			}
			else {
				class folder* temp = new class folder(folder_path[index]);
				it->insert_member(folder_path[index], temp);
				it = temp;
			}
		}
		//File name already exist
		if (it->get_member(folder_path[index]) != nullptr) {
			std::cout << "Error: " << file_path << " already exits." << std::endl;
			return;
		}
		//Create file
		class file* temp = new class file(folder_path[index], content);
		it->insert_member(folder_path[index], temp);
	}

	std::string GetFileContent(const std::string& file_path) {
		//get path
		std::vector<std::string> folder_path = split(file_path, '/');		//split input into separate folder name
		fs_base* it = &root;
		for (int index = 0;index < folder_path.size();index++) {
			if (it->get_member(folder_path[index]) != nullptr) {
				it = it->get_member(folder_path[index]);
			}
			else {											
				return "Error: Folder not found!";
			}
		}
		if (it->get_type() == fs_base::fs_type::FOLDER) {
			return "Error: Found a folder instead of file.";
		}
		return it->get_content()[0];
	}
};