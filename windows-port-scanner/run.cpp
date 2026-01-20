
#include "headers.hpp"
#include "icmp.hpp"
#include "usage.hpp"

int
main() {

    wps::scanner scan;

    scan.init();

    char choice;

	printf("\n *** Windows Port Scanner (wps) *** \n");

    printf ("\n" "windows port scanner is a program to facilitate your view of network in your computer\n");
	printf("type" " 'h' " "to see the help menu with the features.\n");

    while (true) {

        std::cin >> choice;

        switch (choice) {

        case 'l':
            scan.listeningports();
            break;

        case 'p':
            printf("inform destination ip and port to send an icmp echo request\n");
            // ping.specify_id(ip, port);
            break;

        case 'h':
            usage();
            break;

        case 'q':
        case 'Q':
            return 0;

        default:
            printf("unknown option\n");
            break;

        }
    
    }

    return 0;

}
