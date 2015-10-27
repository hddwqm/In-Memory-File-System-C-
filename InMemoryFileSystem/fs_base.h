
#include"prjheader.h"


class fs_base {
	/*base element of a file system, contains element type and name
	has enum fs_type{FILE, FOLDER}
	*/
public:enum fs_type { FILE, FOLDER };
private:
	std::string name;
	fs_type type;
public:
	fs_base(std::string name_in, fs_type type_in) {		//constructor
		name = name_in;
		type = type_in;
	};
	std::string get_name() {			//returns the name
		return name;
	};
	fs_type get_type() {		//returns the type
		return type;
	};
	virtual fs_base* get_member(std::string) {
		return nullptr;
	};
	virtual std::vector<std::string> get_content() = 0;
};