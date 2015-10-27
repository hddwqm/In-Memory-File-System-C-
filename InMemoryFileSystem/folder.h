
#include"prjheader.h"

typedef  std::map<std::string, class fs_base*> folder_struct;

class folder :public fs_base {
	folder_struct content;
public:
	folder(std::string name_in) :fs_base(name_in, fs_base::fs_type::FOLDER) {};

	~folder() {
		for (std::map<std::string, class fs_base*>::iterator it = content.begin();it != content.end();it++) {
			delete it->second;
		}
		content.clear();
	}
	
	fs_base* get_member(std::string name_in) {
		if (content.find(name_in) != content.end()) {
			return content[name_in];
		}
		else {
			return nullptr;
		}
	}
	

	std::vector<std::string> get_content() {
		std::vector<std::string> return_val;
		for (std::map<std::string, class fs_base*>::iterator it = content.begin();it != content.end();it++) {
			return_val.push_back(it->first);
		}
		return return_val;
	};
};