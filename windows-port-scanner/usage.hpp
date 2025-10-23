/*
#ifndef USAGE_GUIDE_HPP
#define USAGE_GUIDE_HPP

// DEFINE FUNCTION TO HANDLE EXIT WHEN AN ERROR OCCURED
#define handle_error(msg) \
        do { perror(msg); exit(EXIT_FAILURE); } while(0)


void
usage(char* path)
{   
	printf("%s [options] -t target\n", path);
	printf("options:\n");
	printf("  -l listening		 show all listening ports\n");
	printf("  -t host            host ip address to send ping requests to\n");
	printf("  -r                 send a single test icmp request and then quit\n");
	printf("In order to improve the speed, lower the delay (-d) between requests or\n");
	printf("increase the size (-s) of the data buffer\n");
}

#endif
*/