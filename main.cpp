#include <cstdint>
#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include <unordered_set>
#include <filesystem>
#include <fstream>

const std::string _name { "crepp" };

void printUsage();
void printHelp();

int main(int argc, char *argv[]) {
	if (argc <= 1) {
		printUsage();
		return 0;
	}

	// Long options with getopt_long
	const struct option longopts[] {
		{ "help", no_argument, 0, '?' },
		{ "version", no_argument, 0, 'V' },
		{ "file", required_argument, 0, 'f' },
		{ 0, 0, 0, 0 }
	};

	int opt { -1 };
	int optIdx {};
	while ((opt = getopt_long(argc, argv, "f:V", longopts, &optIdx)) != -1) {
		switch (opt) {
			case 'f':
				std::cout << "f: file path: " << optarg << '\n';
				break;
			case 'V':
				std::cout << "V: version 1.0" << '\n';
				break;
			case '?':
				printHelp();
				break;
			default:
				printUsage();
				break;
		}
	}

	// for each file name
	// print every line for now
	std::cout << "optind: " << optind << '\n'; // optind is start of non-opt args
	
	// first non-opt arg is PATTERN
	std::string_view pattern { argv[optind] };
	for (int i = optind + 1; i < argc; ++i) {
		// check if arg is a file
		std::ifstream file(argv[i]);

		if (!file) {
			std::cout << _name << ": " << argv[i] << ": No such file or directory\n";
		}

		std::string text {};
		while (getline(file, text)) {
			if (text.find(pattern) != std::string::npos) {
				std::cout << text << '\n';
			}
		}

		// get each line and substring check
		file.close();
	}
	
}

void printUsage() {
	std::cout << "Usage: 'crepp [FILE]'" << '\n';
	std::cout << "Try: 'crepp --help' for more information." << '\n';
}

void printHelp() {
	// Basic information
	std::cout << "Usage: crepp [OPTION]... PATTERNS [FILE]..." << '\n';
	std::cout << "Search for PATTERNS in each FILE." << '\n';
	std::cout << "Example: crepp -i 'hello world' Menu.h main.cpp" << '\n';

	// Options
}

