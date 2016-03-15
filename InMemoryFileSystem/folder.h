
#include"prjheader.h"

typedef  std::map<std::string, class fs_base*> folder_struct;

class folder :public fs_base {
	folder_struct content;
public:
	folder(std::string name_in) :fs_base(name_in, fs_base::fs_type::FOLDER) {  };

	~folder() {
		for (std::map<std::string, class fs_base*>::iterator it = content.begin();it != content.end();it++) {
			delete it->second;
		}
		content.clear();
	}
	
	// Given the name, get the member(folder or file) of the folder, return null_ptr if no such member
	fs_base* get_member(std::string name_in) {
		if (content.find(name_in) != content.end()) {
			return content[name_in];
		}
		else {
			return nullptr;
		}
	}
	
	//Insert a member(folder or file), returns false if the member's name is already used
	bool insert_member(std::string name_in, class fs_base* p) {
		if (content.find(name_in) != content.end()) {
			return false;
		}
		else {
			content[name_in] = p;
			return true;
		}
	}

	//Returns the member name list
	std::vector<std::string> get_content() {
		std::vector<std::string> return_val;
		for (std::map<std::string, class fs_base*>::iterator it = content.begin();it != content.end();it++) {
			return_val.push_back(it->first);
		}
		return return_val;
	};
};