// Port scanner to show all the listening ports on Windows using WinSock2 and Iphlpapi
// this code uses the Windows API to retrieve and display all listening ports on the system.
// more implementation soon.

#ifndef WINDOWS_PORT_SCANNER_HEADERS_HPP
#define WINDOWS_PORT_SCANNER_HEADERS_HPP

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <iostream>
#include <vector>

//#include "usage.hpp"

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

#define handle_error(msg) \
        do { perror(msg); exit(EXIT_FAILURE); } while(0)

/*
void
usage(char* path)
{
	printf("%s [options] -t target\n", path);
	printf("options:\n");
	printf("  -l listening		 show all listening ports\n");
	printf("  -t host            host ip address to send ping requests to\n");
	printf("  -r                 send a single test icmp request and then quit\n");
	printf("In order to improve the speed, lower the delay (-d) between requests or\n");
	printf("increase the size (-s) of the data buffer\n");
}
*/

#ifndef VAR_STRUCTS_HPP
#define VAR_STRUCTS_HPP

struct config
{

	PMIB_TCPTABLE_OWNER_PID pTcpTable; // get the id and the ipv4 tcp links
	DWORD dwSize = 0;
	DWORD dwRetVal = 0;

};

#endif


namespace wps
{ // windows-port-scanner

	class scanner
	{

	public:

		bool init();
		void ports(); // for table all ports in id host
		void listeningports();
		void run();
	
	private:

		WSADATA wsadata;
		config c;
	};
}

#endif