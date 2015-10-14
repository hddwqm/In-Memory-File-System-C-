#pragma once

class fs_base {
	/*base element of a file system, contains element type and name
	has enum fs_type{FILE, FOLDER}
	*/
public:enum fs_type { FILE, FOLDER };
private:
	string name;
	fs_type type;
public:
	fs_base(string name_in, fs_type type_in) {
		name = name_in;
		type = type_in;
	}
	string get_name() {
		return name;
	}
	fs_type get_type() {
		return type;
	}
	virtual fs_base* get_member(string) = 0;
	virtual string get_content() = 0;
};