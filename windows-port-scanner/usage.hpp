#ifndef USAGE_GUIDE_HPP
#define USAGE_GUIDE_HPP

#define handle_error(msg) \
        do { perror(msg); exit(EXIT_FAILURE); } while(0)

void menu() {
    printf("\n\t********************************Menu********************************:\n");
    printf("-l. list off tcp table\n");
    printf("-q. quit\n");

}

#endif
