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
	 *  Runs the main program.
	 *  If runnable, performs crepp on each file in filepaths.
	 *  Otherwise, does nothing.
	 *	Errors should have been produced at initialisation.
	 */
	void run();

private:
	// Prerequisite check, set to false on error
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
	 *  Returns false if an unknown option or terminating option was found.
	 */
	void parseOptions(int argc, char *argv[]);

	/**
	 *  Retrieves PATTERN from argv.
	 */
	void parsePattern(int argc, char *argv[]);
	
	/**
	 *  Retrieves filepaths from argv.
	 *  Assumes optind has been placed at the first file path.
	 *  If path leads to a directory and recursive is true, recursively parse filepaths inside.
	 */
	void parseFilepaths(int argc, char *argv[]);
};
