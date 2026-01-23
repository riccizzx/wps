// Port scanner to show all the listening ports on Windows using WinSock2 and Iphlpapi
// this code uses the Windows API to retrieve and display all listening ports on the system.
// more implementation soon.

#ifndef WINDOWS_PORT_SCANNER_HEADERS_HPP
#define WINDOWS_PORT_SCANNER_HEADERS_HPP

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <IcmpAPI.h>

#include <stdio.h>
#include <iostream>
#include <vector>

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")


#define handle_error(msg) \
        do { perror(msg); exit(EXIT_FAILURE); } while(0)



#ifndef VAR_STRUCTS_HPP
#define VAR_STRUCTS_HPP

struct config
{

	PMIB_TCPTABLE_OWNER_PID pTcpTable; // get the id and the ipv4 tcp links
	PMIB_UDPTABLE_OWNER_PID pUdpTable; // get the id and the ipv4 udp links
	DWORD dwSize = 0;
	DWORD dwRetVal = 0;

};

#endif


namespace wps
{ 

	class scanner
	{

	public:

		bool init();
		void ports(); // for table all ports in id host
		void listeningports();
		void adapter();
	
	private:

		WSADATA wsadata;
		config c;
	};
}

#endif