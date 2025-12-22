
#include "icmp.hpp"

// ICMP related functionality will be implemented here in the future.

void icmp::icmp_ping::specify_id(std::string ip, int port) {
	// Placeholder for specifying target IP and port for ICMP ping

	std::string target_;
	const int target_port = port;

	target_ = ip;
	htons(target_port);

	

}