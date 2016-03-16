#include"prjheader.h"

/* 
A simple program to simulate basic file operation.
mkdir: Create directory 
add: Create file with specified content
ls: List subdirectories and files in the specified directory 
show: Show the content for specified file

*/


int main(int argc, char* argv[]) {
	FileSystem fs;
	std::string command = "";
	std::string path = "";

	/*// should print ""
	std::cout << join(fs.Ls("/")) << std::endl;
	fs.MkdirP("/a/b/c");
	fs.AddFileWithContent("/a/b/c/d", "hello world");
	// should print a
	std::cout << join(fs.Ls("/")) << std::endl;
	// should print d
	std::cout << join(fs.Ls("/a/b/c")) << std::endl;
	// should print error
	std::cout << join(fs.Ls("/a/b/c/d")) << std::endl;
	// should print hello world
	std::cout << fs.GetFileContent("/a/b/c/d")<<std::endl;*/

	do {
		std::cout << ">";
		std::cin >> command;
		if (command == "ls") {
			std::cin >> path;
			if (path.find_first_not_of("abcdefghijklmnopqrstuvwxyz/") != std::string::npos) {
				std::cout << "Illegal path." << std::endl;
			}
			std::cout << join(fs.Ls(path)) << std::endl;
		}
		else if (command == "mkdir") {
			std::cin >> path;
			if (path.find_first_not_of("abcdefghijklmnopqrstuvwxyz/") != std::string::npos) {
				std::cout << "Illegal path." << std::endl;
			}
			fs.MkdirP(path);
		}
		else if (command == "add") {
			std::cin >> path;
			if (path.find_first_not_of("abcdefghijklmnopqrstuvwxyz/") != std::string::npos) {
				std::cout << "Illegal path." << std::endl;
			}
			std::string in = "";
			std::cin >> in;
			fs.AddFileWithContent(path, in);
		}
		else if (command == "show") {
			std::cin >> path;
			if (path.find_first_not_of("abcdefghijklmnopqrstuvwxyz/") != std::string::npos) {
				std::cout << "Illegal path." << std::endl;
			}
			std::cout << fs.GetFileContent(path) << std::endl;
		}
		else if (command == "end") {
			break;
		}
		else if (command == "clear") {
			system("cls");
		}
		else {
			std::cout << "Unknown command." << std::endl;
		}
	} while (1);


	return 0;
}
