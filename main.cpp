#include "CreppClass.hpp"

#include <iostream>
#include <getopt.h>
#include <memory>

int main(int argc, char *argv[]) {
	std::unique_ptr<CreppClass> creppInstance { std::make_unique<CreppClass>(argc, argv) };
	creppInstance.run();
}

void printHelp() {
	// Basic information
	std::cout << "Usage: crepp [OPTION]... PATTERNS [FILE]..." << '\n';
	std::cout << "Search for PATTERNS in each FILE." << '\n';
	std::cout << "Example: crepp -i 'hello world' Menu.h main.cpp" << '\n';

	// Options
}
