
#ifdef		_WIN32
#define		ICMP_HPP

#include "headers.hpp"

int ping(const char* host, int cnt = 4);

#define PING_TIMEOUT 1000 // ms

#endif	   #ICMP_HPP