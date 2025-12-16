
#include "headers.hpp"

bool
wps::scanner::init()
{
    try {

        if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
            handle_error("failed!");
            return FALSE;
        }

    }
    catch (const std::exception& e)
    {
        handle_error("error in initialize socket API ", e.what());
        return FALSE;
    }

    return TRUE;

}