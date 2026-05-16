#include <vector>
#include <string>

class CreppClass {
public:

private:
	// Toggles
	bool vInvert {};
	bool recursive {};

	// PATTERN
	std::vector<std::string> patterns {};

	// FILE
	std::vector<std::string> filepaths {};

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
	void getOptions(int argc, char *argv[]);
	
	/**
	 *  Retrieves filepaths from argv.
	 */
	void getFilepaths(int argc, char *argv[], int optind);
};
