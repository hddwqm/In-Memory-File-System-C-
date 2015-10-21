#pragma once

using namespace std;

class FileSystem {
	folder root;
public:
	FileSystem() :root(string("")) {
	}
	vector<string> Ls(const string& path) {
		// IMPLEMENT ME
		//get path
		vector<string> folder_path = split(path, '/');		//split input into separate folder name
		folder* fs_root = &root;
		fs_base* it = &root;
		for (int index = 0;index < folder_path.size();index++) {
			if (it->get_member(folder_path[index]) != nullptr) {
				it = it->get_member(folder_path[index]);
			}
			else {											//return null pointer if there is no such name or if the name represents a file
				vector<string> return_val;
				return_val.push_back("folder not found!");
				return return_val;
			}
		}
		return it->get_content;
	}

	void MkdirP(const string& dir_path) {
		// IMPLEMENT ME
	}

	void AddFileWithContent(const string& file_path, const string& content) {
		// IMPLEMENT ME
	}

	string GetFileContent(const string& file_path) {
		// IMPLEMENT ME
		return "";
	}
};