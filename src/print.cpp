#include "../include/print.hpp"

#include <iostream>

// Printing functions
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
