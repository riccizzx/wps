#include "headers.hpp"

int
main(int argc, char **argv) {

	int opt;
	wps::scanner scan;

	scan.init();

	//menu(*argv);

	// parse command line options
	for (opt = 1; opt < argc; opt++) {
		if (argv[opt][0] == '-') {
			switch (argv[opt][1]) {
			case 'l':
				usage(*argv);
				return 0;
			}
		}
	}



	return 0;
}