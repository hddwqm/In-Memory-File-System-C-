#pragma once

using namespace std;

class FileSystem {
	folder root;
public:
	FileSystem() :root("") {
	}
	vector<string> Ls(const string& path) {
		// IMPLEMENT ME
		//get path
		vector<string> folder_path = split(path, '/');
		folder* fs_root = &root;
		fs_base* it = &root;
		for (int index = 0;index < folder_path.size;index++) {
			if (it->get_member(folder_path[index]) != nullptr) {
				it = it->get_member(folder_path[index]);
			}
			else {
				// IMPLEMENT ME
			}
		}
		vector<string> output;
		return output;
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