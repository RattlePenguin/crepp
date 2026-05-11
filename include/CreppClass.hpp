#include <vector>
#include <string>

class CreppClass {
public:

private:
	bool vInvert {};
	std::vector<std::string> patterns {};

	/** 
	 *  Performs crepp on a given path
	 *  Matches lines with each PATTERN in patterns
	 *  Colour highlights PATTERN in lines (WIP)
	 *  If multiple files were given, filename should be prepended to line (WIP)
	 *  If a directory is given and -r (recursive) was not enabled, produce error
	 */
	void getOptions(int argc, char *argv[], )
	void crepp(std::string filepath);
};
