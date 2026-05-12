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
	// if no args are given
	if (argc <= 1) {
		printUsage();
		return 0;
	}

	// first non-opt arg is PATTERN
	std::string_view pattern { argv[optind] };

	// if no subsequent args, read from stdin
	if (optind + 1 >= argc) {
		std::string text {};
		while (getline(std::cin, text)) {
			if (text.find(pattern) != std::string::npos) {
				std::cout << text << '\n';
			}
		}
		return 0;
	}

	// every subsequent arg is a filename
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
