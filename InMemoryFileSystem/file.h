#pragma once
class file : fs_base {
	string content;
public:
	file(string name_in, string content_in = "") :fs_base(name_in, fs_base::fs_type::FILE) {
		content = content_in;
	}
	void change_content(string in) {
		content = in;
	}
	string get_content() {
		return content;
	}
};