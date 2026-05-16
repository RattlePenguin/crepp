#include "CreppClass.hpp"
#include "Option.hpp"

#include <iostream>

// Forward declarations
void printUsage();
void printHelp();

void CreppClass::crepp(int argc, char *argv[]) {
	getOptions(argc, argv);
	getFilepaths(argc, argv);
}

void CreppClass::getOptions(int argc, char *argv[]) {
	// Compare opt with flag char to obtain given opt
	int opt { -1 };
	// optIdx is updated to corresponding opt index in longopts
	int optIdx {};
	
	// getopt_long reads longopts from Option.hpp
	while ((opt = getopt_long(argc, argv, "f:V", longopts, &optIdx)) != -1) {
		switch (opt) {
			case 'V':
				std::cout << "V: version 1.0" << '\n';
				break;
			case 'f':
				std::cout << "f: file path: " << optarg << '\n';
				break;
			case 'v':
				std::cout << "v: vInvert set to true" << '\n';
				vInvert = true;
				break;
			case 'r':
				std::cout << "r: recursive set to true" << '\n';
				recursive = true;
				break;
			case '?':
				std::cout << "?: print help" << '\n';
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
	std::cout << "TODO Put options information here.\n";
}

