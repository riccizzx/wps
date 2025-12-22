
#ifdef _WIN32
#define ICMP_HPP
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "headers.hpp"

namespace icmp {

	class icmp_ping {

	public:

		

	private:

		void specify_id(std::string ip, const int port);
		SOCKET raw_socket;


	};

}

#endif