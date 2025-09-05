#include <stdio.h>
#include "string.h"
#include "stdbool.h"

#ifndef NO_DEBUG
#define DEBUG(...)                                                             \
    do {                                                                       \
        fprintf(stderr, "%d: %s    ", __LINE__, __FILE__);                     \
        fprintf(stderr, __VA_ARGS__);                                          \
    } while (0);
#else
#define NO_DEBUG
#define DEBUG(...)
#endif

int main(int argc, char **argv)
{
    char input[50];
    char loopEndstr[] = "quit";
    int  endLoop      = false;

    while (!endLoop) {
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0';
        endLoop = strcmp(input, loopEndstr) == 0 ? true : false;
        // printf("in side the loop endloop : %d \n", endLoop);

        if (endLoop) {
            printf("program is gone quit");
        } else {
            printf(" %s,\ninputlen : %lu \n", input, strlen(input));
        }
    };

    for (int i = 0; i < argc; ++i)
        printf("%s\n", argv[i]);
    return 0;
}
