
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
	std::cin >> choice;

	switch (choice) {
	
	case 'l':
		scan.listeningports();
		
	}

	return 0;
}