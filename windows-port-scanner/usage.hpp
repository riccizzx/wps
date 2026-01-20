
#ifndef WINDOWS_PORT_SCANNER_USAGE_HPP
#define WINDOWS_PORT_SCANNER_USAGE_HPP


#include <iostream>


inline void
usage()
{
	std::cout << "Usage: wps [options]\n";
	std::cout << "  -l listening      show all listening ports from host\n";
	std::cout << "  -h host           host ip address to send ping requests to\n";
	std::cout << "  -r                send a single test icmp request and then quit\n";
	std::cout << "  -q to quit wps\n";

}


#endif // WINDOWS_PORT_SCANNER_USAGE_HPP