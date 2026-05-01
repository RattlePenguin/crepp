#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

void printUsage();

int main(int argc, char *argv[]) {
	if (argc <= 1 || argc > 2) {
		printUsage();
		return 0;
	}

	// Get all options and flip flags
	parseOptions();

	// Open file and print every line

}

void printUsage() {
	std::cout << "Usage: 'crepp [FILE]'" << '\n';
	std::cout << "Try: 'crepp --help' for more information." << '\n';
}

void parseOptions(int argc, char *argv[]) {
	int opt { -1 };
	while ((opt = getopt(argc, argv, "f:v")) != -1) {
		switch (opt) {
			case 'f':
				// use optarg as path to file
				std::cout << "file path: " << optarg << '\n';
			case 'v':
			case '?':
				printUsage();
				break;
		}
	}
}

void printHelp() {

}
