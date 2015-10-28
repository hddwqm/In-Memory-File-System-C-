
#include"prjheader.h"


class FileSystem {
	folder root;
public:
	FileSystem() :root(std::string("")) {
	}
	std::vector<std::string> Ls(const std::string& path) {
		//get path
		std::vector<std::string> folder_path = split(path, '/');		//split input into separate folder name
		folder* fs_root = &root;
		fs_base* it = &root;
		for (int index = 0;index < folder_path.size();index++) {
			if (it->get_member(folder_path[index]) != nullptr) {
				it = it->get_member(folder_path[index]);
			}
			else {											//return null pointer if there is no such name or if the name represents a file
				std::vector<std::string> return_val;
				return_val.push_back("folder not found!");
				return return_val;
			}
		}
		return it->get_content();
	}

	void MkdirP(const std::string& dir_path) {
		std::vector<std::string> folder_path = split(dir_path, '/');
		fs_base* it = &root;
		for (int index = 0;index < folder_path.size();index++) {
			if (it->get_member(folder_path[index]) != nullptr) {
				it = it->get_member(folder_path[index]);
			}
			else if (it->get_type() == fs_base::fs_type::FILE) {
				return;			//temp
			}
			else {
				class folder* temp = new class folder(folder_path[index]);
				it->insert_member(folder_path[index], temp);
				it = temp;
			}
		}
		// IMPLEMENT ME
	}

	void AddFileWithContent(const std::string& file_path, const std::string& content) {
		// IMPLEMENT ME
	}

	std::string GetFileContent(const std::string& file_path) {
		// IMPLEMENT ME
		return "";
	}
};