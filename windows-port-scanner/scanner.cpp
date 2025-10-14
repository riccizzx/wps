#include "headers.hpp"

void wps::scanner::ports()
{
    
    c.pTcpTable = (MIB_TCPTABLE_OWNER_PID*)malloc(sizeof(MIB_TCPTABLE_OWNER_PID));
    c.dwSize = sizeof(MIB_TCPTABLE_OWNER_PID);
    
    // get required buffer size
    if ((c.dwRetVal = GetExtendedTcpTable(c.pTcpTable, &c.dwSize, TRUE, AF_INET,
        TCP_TABLE_OWNER_PID_ALL, 0)) == ERROR_INSUFFICIENT_BUFFER) // get all tcp table 
    {
    
        free(c.pTcpTable); 
        c.pTcpTable = (MIB_TCPTABLE_OWNER_PID*)malloc(c.dwSize);
    
    }

}

void wps::scanner::listeningports()
{

    // allocate initial buffer
    c.pTcpTable = (MIB_TCPTABLE_OWNER_PID*)malloc(sizeof(MIB_TCPTABLE_OWNER_PID));
    c.dwSize = sizeof(MIB_TCPTABLE_OWNER_PID);

    // get required buffer size
    if ((c.dwRetVal = GetExtendedTcpTable(c.pTcpTable, &c.dwSize, TRUE, AF_INET,
        TCP_TABLE_OWNER_PID_ALL, 0)) == ERROR_INSUFFICIENT_BUFFER)
    {

        free(c.pTcpTable);
        c.pTcpTable = (MIB_TCPTABLE_OWNER_PID*)malloc(c.dwSize);

    }

    // retrieve TCP table
    if ((c.dwRetVal = GetExtendedTcpTable(c.pTcpTable, &c.dwSize, TRUE, AF_INET,
        TCP_TABLE_OWNER_PID_ALL, 0)) == NO_ERROR)
    {

        for (DWORD i = 0; i < c.pTcpTable->dwNumEntries; i++) {
            MIB_TCPROW_OWNER_PID row = c.pTcpTable->table[i];

            if (row.dwState == MIB_TCP_STATE_LISTEN) {
                // Convert IP address using InetNtop
                struct in_addr ipAddr;
                ipAddr.S_un.S_addr = row.dwLocalAddr;

                char ipStr[INET_ADDRSTRLEN] = { 0 };
                if (InetNtopA(AF_INET, &ipAddr, ipStr, INET_ADDRSTRLEN) == NULL) {
                    handle_error("Failed to convert IP address\n");
                    continue;
                }

                int port = ntohs((u_short)row.dwLocalPort);

                std::cout << "LISTENING on IP: " << ipStr
                    << " Port: " << port
                    << " PID: " << row.dwOwningPid << std::endl;
            }
        }
    }
    else {
        handle_error("GetExtendedTcpTable failed with code: ", c.dwRetVal);
    }

    if (c.pTcpTable) {
        free(c.pTcpTable);
    }
}

void wps::scanner::run() {
    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
        handle_error("WSAStartup failed: ", WSAGetLastError());
        exit(EXIT_FAILURE);
    }

    //ports();
    listeningports();
    WSACleanup();
}