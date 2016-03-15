
#include"prjheader.h"

class file : public fs_base {
	std::string content;
public:
	file(std::string name_in, std::string content_in = "") :fs_base(name_in, fs_base::fs_type::FILE) {
		content = content_in;
	}

	//
	void change_content(std::string in) {
		content = in;
	}

	//Returns the content of file
	std::vector<std::string> get_content() {
		std::vector<std::string> return_val;
		return_val.push_back(content);
		return return_val;
	}
};