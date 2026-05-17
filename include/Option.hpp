#pragma once
/**
 *  Thinking of mapping shortopts to longopts using a hashmap
 *  How to also do no_argument / etc, flag field and val
 */

#include <getopt.h>

const int OPT_HELP { 256 };

const struct option longopts[] {
	{ "help", no_argument, 0, OPT_HELP },
	{ "version", no_argument, 0, 'V' },
	{ "file", required_argument, 0, 'f' },
	{ "invert-match", no_argument, 0, 'v' }, // these are toggles, look at using flag
	{ "recursive", no_argument, 0, 'r' },
	{ 0, 0, 0, 0 }
};
