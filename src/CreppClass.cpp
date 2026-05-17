#include "CreppClass.hpp"
#include "Option.hpp"
#include "print.hpp"

#include <iostream>
#include <fstream>

CreppClass::CreppClass(int argc, char *argv[]) {
	if (argc <= 1) {
		printUsage();
	}
	parseAll(argc, argv);
}

void CreppClass::run() {
	for (std::string filepath : filepaths) {
		crepp(filepath);
	}
}

void CreppClass::crepp(std::string filepath) {
	// check if arg is a file
	std::ifstream file(filepath);

	if (!file) {
		std::cout << "crepp: " << filepath << ": No such file or directory\n";
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

void CreppClass::parseAll(int argc, char *argv[]) {
	parseOptions(argc, argv);
	parseFilepaths(argc, argv);
}

int CreppClass::parseOptions(int argc, char *argv[]) {
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

void parsePattern(int argc, char *argv[]) {
}

void parseFilepaths(int argc, char *argv[]) {
	
}

