#pragma once

typedef  map<string, class fs_base*> folder_struct;

class folder :public fs_base {
	folder_struct content;
public:
	fs_base* get_member(string name_in) {
		if (content.find(name_in) != content.end()) {
			return content[name_in];
		}
		else {
			return nullptr;
		}
	}
	folder(string name_in) :fs_base(name_in, fs_base::fs_type::FOLDER) {};

	vector<string> get_content() {
		vector<string> return_val;
		for (map<string, class fs_base*>::iterator it = content.begin();it != content.end();it++) {
			return_val.push_back(it->first);
		}
		return return_val;
	};
};