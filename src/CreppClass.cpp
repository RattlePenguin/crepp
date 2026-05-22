#include "CreppClass.hpp"
#include "Option.hpp"
#include "print.hpp"

#include <iostream>
#include <fstream>

CreppClass::CreppClass(int argc, char *argv[]) {
	if (argc <= 1) {
		printUsage();
	} else {
		parseAll(argc, argv);
	}
}

void CreppClass::run() {
	if (!runnable) {
		std::cout << "Crepp could not run.\n";
		return;
	}
	for (std::string filepath : filepaths) {
		crepp(filepath);
	}
}

void CreppClass::crepp(std::string filepath) {
	std::ifstream file(filepath);

	// Check if file exists
	if (!file) {
		std::cout << "crepp: " << filepath << ": No such file or directory\n";
	}

	// TODO check if file is a directory

	std::string text {};
	while (getline(file, text)) {
		for (std::string pattern : patterns) {
			// Substring matching
			if (text.find(pattern) != std::string::npos) { // TODO text highlighting
				std::cout << text << '\n';
			}
		}
	}

	file.close();
}

void CreppClass::parseAll(int argc, char *argv[]) {
	parseOptions(argc, argv);
	parseFilepaths(argc, argv);
}

void CreppClass::parseOptions(int argc, char *argv[]) {
	// Set true to start with, invalid / terminating options will set false
	runnable = true;

	// Compare opt with flag char to obtain given opt
	int opt { -1 };
	// optIdx is updated to corresponding opt index in longopts
	int optIdx {};
	
	// getopt_long reads longopts from Option.hpp
	while ((opt = getopt_long(argc, argv, "f:V", longopts, &optIdx)) != -1) {
		switch (opt) {
			case 'V': // terminating
				std::cout << "V: version 1.0" << '\n'; // printVersion
				runnable = false;
				return;
			case OPT_HELP: // terminating
				printHelp();
				runnable = false;
				return;
			case 'f':
				std::cout << "f: taking patterns from file path: " << optarg << '\n';
				// TODO add to patterns 
				break;
			case 'v':
				std::cout << "v: vInvert set to true" << '\n';
				vInvert = true;
				break;
			case 'r':
				std::cout << "r: recursive set to true" << '\n';
				recursive = true;
				break;
			default: // invalid
				std::cout << "crepp: invalid option -- '" << argv[optind - 1] << "'\n";
				printUsage();
				runnable = false;
				return;
		}
	}
}

void CreppClass::parsePatterns(int argc, char *argv[]) {

}

void CreppClass::parseFilepaths(int argc, char *argv[]) {
	for (int i = optind; i < argc; ++i) {
		filepaths.push_back(argv[i]);
	}
}
