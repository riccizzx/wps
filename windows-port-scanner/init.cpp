
#include "headers.hpp"

bool
wps::scanner::init()
{
    try {

        WSAStartup(MAKEWORD(2, 2), &wsadata);
    }
    
    catch (const std::exception& e)
    
    {

        handle_error("error in initialize socket API ", e.what());
		printf("%s", "run with administrator privileges\n");
        return FALSE;
    
    }

    return TRUE;

}