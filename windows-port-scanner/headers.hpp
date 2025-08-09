//port scanner to show all the listening ports on Windows using WinSock2 and Iphlpapi
// this code uses the Windows API to retrieve and display all listening ports on the system.
// more implementation soon.
#pragma once
#ifndef WINDOWS_PORT_SCANNER_HEADERS_HPP
#define WINDOWS_PORT_SCANNER_HEADERS_HPP

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <iostream>
#include <vector>

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")
#endif // WINDOWS_PORT_SCANNER_HEADERS_HPP

namespace WindowsPortScanner {
	class Scanner {
	public:
		void ListeningPorts();
		void Run();
	private:
		WSADATA wsadata;
	};
}