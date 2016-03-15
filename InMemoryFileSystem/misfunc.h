#include"prjheader.h"

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	std::stringstream ss(s);
	std::string item;
	while (getline(ss, item, delim)) {
		if (item != "") {
			elems.push_back(item);
		}
		
	}
	return elems;
}

std::string join(const std::vector<std::string>& input) {
	std::string output = "";
	bool has_data = false;
	for (size_t i = 0; i < input.size(); ++i) {
		has_data = true;
		output += input[i];
		output += ", ";
	}
	if (has_data) {
		output = output.substr(0, output.length() - 2);
	}
	return output;
}
