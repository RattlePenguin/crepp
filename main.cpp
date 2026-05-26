#include "include/CreppClass.hpp"

#include <iostream>
#include <getopt.h>
#include <memory>

int main(int argc, char *argv[]) {
	std::unique_ptr<CreppClass> creppInstance { std::make_unique<CreppClass>(argc, argv) };
	creppInstance->run();
}

