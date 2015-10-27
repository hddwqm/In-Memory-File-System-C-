#include"prjheader.h"


int main(int argc, char* argv[]) {
	FileSystem fs;

	// should print ""
	std::cout << join(fs.Ls("/")) << std::endl;
	fs.MkdirP("/a/b/c");
	fs.AddFileWithContent("/a/b/c/d", "hello world");
	// should print a
	std::cout << join(fs.Ls("/")) << std::endl;
	// should print d
	std::cout << join(fs.Ls("/a/b/c")) << std::endl;
	// should print d
	std::cout << join(fs.Ls("/a/b/c/d")) << std::endl;
	// should print hello world
	std::cout << fs.GetFileContent("/a/b/c/d");
}
