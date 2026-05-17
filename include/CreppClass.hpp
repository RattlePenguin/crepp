#pragma once

#include "Option.hpp"

#include <vector>
#include <string>

class CreppClass {
public:
	/**
	 *  Initialises the class using argc and argv.
	 *  Parses options, patterns and file paths.
	 */
	CreppClass(int argc, char *argv[]);

	/**
	 *  Performs crepp on each file path in filepaths.
	 */
	void run();

private:
	bool runnable {};

	// Option toggles
	bool vInvert {};
	bool recursive {};

	// Vector of PATTERN
	std::vector<std::string> patterns {};

	// Vector of FILE
	std::vector<std::string> filepaths {};

	/**
	 *  Performs crepp on a given path.
	 *  Matches lines with each PATTERN in patterns.
	 *  Colour highlights PATTERN in lines (WIP)
	 *  If multiple files were given, filename should be prepended to line (WIP)
	 *  If a directory is given and -r (recursive) was not enabled, produce error
	 */
	void crepp(std::string filepath);

	/**
	 *  Performs parsing operations on command line input for use in crepp.
	 */
	void parseAll(int argc, char *argv[]);

	/**
	 *  Retrieves options from argv.
	 *  Returns the index of the first non-option argument, i.e. PATTERN
	 */
	int parseOptions(int argc, char *argv[]);

	/**
	 *  Retrieves PATTERN from argv.
	 */
	void parsePattern(int argc, char *argv[]);
	
	/**
	 *  Retrieves filepaths from argv.
	 *  Assumes optind has been placed at the first file path.
	 */
	void parseFilepaths(int argc, char *argv[]);
};
