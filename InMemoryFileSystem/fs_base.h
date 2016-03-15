
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

	//returns the name
	std::string get_name() {			
		return name;
	};

	//returns the type
	fs_type get_type() {		
		return type;
	};

	virtual fs_base* get_member(std::string) {
		return nullptr;
	};


	virtual bool insert_member(std::string, class fs_base *p = nullptr) {
		return false;
	};


	virtual std::vector<std::string> get_content() = 0;
};