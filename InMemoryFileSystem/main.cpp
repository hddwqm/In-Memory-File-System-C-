#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include "fs_base.h"
#include "file.h"
#include "folder.h"
#include "FileSystem.h"

using namespace std;

vector<string> split(const string &s, char delim) {
	vector<string> elems;
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

string join(const vector<string>& input) {
	string output = "";
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

int main(int argc, char* argv[]) {
	FileSystem fs;

	// should print ""
	cout << join(fs.Ls("/")) << endl;
	fs.MkdirP("/a/b/c");
	fs.AddFileWithContent("/a/b/c/d", "hello world");
	// should print a
	cout << join(fs.Ls("/")) << endl;
	// should print d
	cout << join(fs.Ls("/a/b/c")) << endl;
	// should print d
	cout << join(fs.Ls("/a/b/c/d")) << endl;
	// should print hello world
	cout << fs.GetFileContent("/a/b/c/d");
}
