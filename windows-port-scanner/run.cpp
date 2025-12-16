
#include "headers.hpp"
#include "usage.hpp"

int
main() {

	wps::scanner scan;

	try {
		scan.init();

	
	}
	catch (const std::exception& e) {
		handle_error("error in main ", e.what());
		return EXIT_FAILURE;
	
	}

	usage("windows-port-scanner");

	char choice;

	do {

		std::cin >> choice;

		switch (choice) {

		case 'l':
			scan.listeningports();

		}
	}while (choice != 'q');

	return 0;
}
