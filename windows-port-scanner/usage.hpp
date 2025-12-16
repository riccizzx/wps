
#ifndef WINDOWS_PORT_SCANNER_USAGE_HPP
#define WINDOWS_PORT_SCANNER_USAGE_HPP

#include <iostream>

void usage(const char* path)
{
	std::cout << path << " [options] -t target\n";
	std::cout << "options:\n";
	std::cout << "  -l listening      show all listening ports from host\n";
	std::cout << "  -t host           host ip address to send ping requests to\n";
	std::cout << "  -r                send a single test icmp request and then quit\n";
	std::cout << "In order to improve the speed, lower the delay (-d) between requests or\n";
	std::cout << "increase the size (-s) of the data buffer\n";

}


#endif // WINDOWS_PORT_SCANNER_USAGE_HPP