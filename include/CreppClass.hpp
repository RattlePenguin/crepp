#include <vector>
#include <string>

class CreppClass {
public:

private:
	// Toggles
	bool vInvert {};
	bool recursive {};

	// Vector of PATTERN
	std::vector<std::string> patterns {};

	// Vector of FILE
	std::vector<std::string> filepaths {};

	/**
	 *  Initialises the class using argc and argv.
	 *  Parses options, patterns and file paths, then performs crepp on each file.
	 */
	void initialise(int argc, char *argv[]);

	/**
	 *  Performs crepp on a given path.
	 *  Matches lines with each PATTERN in patterns.
	 *  Colour highlights PATTERN in lines (WIP)
	 *  If multiple files were given, filename should be prepended to line (WIP)
	 *  If a directory is given and -r (recursive) was not enabled, produce error
	 */
	void crepp(int argc, char *argv[]);

	/**
	 *  Retrieves options from argv.
	 */
	void parseOptions(int argc, char *argv[]);
	
	/**
	 *  Retrieves filepaths from argv.
	 */
	void parseFilepaths(int argc, char *argv[], int optind);
};
