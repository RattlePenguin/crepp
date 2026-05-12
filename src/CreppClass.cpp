#include "CreppClass.hpp"
#include "Option.hpp"

#include <iostream>

// Forward declarations
void printUsage();
void printHelp();

void CreppClass::getOptions(int argc, char *argv[]) {
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
			case 'v':
				vInvert = true;
				break;
			case 'r':
				recursive = true;
				break;
			case '?':
				printHelp();
				break;
			default:
				printUsage();
				break;
		}
	}
}

/**
 *  Prints usage message.
 */
void printUsage() {
	std::cout << "Usage: 'crepp [FILE]'" << '\n';
	std::cout << "Try: 'crepp --help' for more information." << '\n';
}

/**
 *  Prints help message.
 */
void printHelp() {
	// Basic information
	std::cout << "Usage: crepp [OPTION]... PATTERNS [FILE]..." << '\n';
	std::cout << "Search for PATTERNS in each FILE." << '\n';
	std::cout << "Example: crepp -i 'hello world' Menu.h main.cpp" << '\n';

	// Options information
}

void CreppClass::crepp(std::string filepath) {
}
