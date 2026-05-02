#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include <unordered_set>
#include <filesystem>
#include <fstream>

// namespace fs = std::filesystem;

// Long options with getopt_long
static struct option longopts[] {
	{ "help", no_argument, 0, '?' },
	{ "verbose", no_argument, 0, 'v' },
	{ "file", required_argument, 0, 'f' },
	{ 0, 0, 0, 0 }
};

void printUsage();

int main(int argc, char *argv[]) {
	if (argc <= 1) {
		printUsage();
		return 0;
	}

	int opt { -1 };
	int optIdx {};
	while ((opt = getopt_long(argc, argv, "f:v", longopts, &optIdx)) != -1) {
		switch (opt) {
			case 'f':
				std::cout << "file path: " << optarg << '\n';
				break;
			case 'v':
				std::cout << "verbose is true " << '\n';
				break;
			case '?':
				printUsage();
				break;
		}
	}

	for (int i = optIdx; i < argc; ++i) {
		std::cout << "non opt arg: " << argv[i] << '\n';
	}
}

void printUsage() {
	std::cout << "Usage: 'crepp [FILE]'" << '\n';
	std::cout << "Try: 'crepp --help' for more information." << '\n';
}

