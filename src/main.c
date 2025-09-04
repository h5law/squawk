#include <stdio.h>

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
    for (int i = 0; i < argc; ++i)
        printf("%s\n", argv[i]);
    return 0;
}
