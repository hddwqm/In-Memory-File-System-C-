#pragma once
class file : public fs_base {
	string content;
public:
	file(string name_in, string content_in = "") :fs_base(name_in, fs_base::fs_type::FILE) {
		content = content_in;
	}
	void change_content(string in) {
		content = in;
	}
	vector<string> get_content() {
		vector<string> return_val;
		return_val.push_back(content);
		return return_val;
	}
};