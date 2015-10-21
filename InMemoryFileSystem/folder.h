#pragma once
class folder :public fs_base {
	map<string, class fs_base*> content;
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
		// IMPLEMENT ME
		return return_val;
	};
};