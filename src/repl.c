/* $squawk: repl.c */

#include <stdio.h>
#include <string.h>

#include "repl.h"

#define MAXTOKENSIZE 65 /* 64 + NULL terminator */

const char *quit = "quit\n";

int repl_echo(void)
{
    char input[MAXTOKENSIZE] = {0};
    void *ptr = fgets(input, MAXTOKENSIZE, stdin);
    while (ptr) {
        printf("%s", input);
        if (memcmp(input, quit, 6) == 0)
            return 1;

        memset(input, 0, MAXTOKENSIZE);
        ptr = fgets(input, MAXTOKENSIZE, stdin);
    }

    return 0;
}

// vim: ft=c ts=4 sts=4 sw=4 et ai cin
