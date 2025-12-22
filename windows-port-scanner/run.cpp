
#include "headers.hpp"
#include "icmp.hpp"
#include "usage.hpp"

int
main() {

	wps::scanner scan;
	icmp::icmp_ping ping;

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

		case 'h':
			printf("inform destination ip and port to send a icmp/echo-rqst\n");
			//ping.specify_id(std::string ip, const int port);

		}


	}while (choice != 'q');

	return 0;
}
