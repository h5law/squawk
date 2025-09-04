#include <stdio.h>
#include <string.h>

// NOTE: Trying to implement the REPL here
// TODO: input string is limited to 50 char, and fgets only gets one line input
//  will need to fix this , soon

int main()
{
    char input[50];
    char loopEndstr[] = "quit";
    int  endLoop;

    while (endLoop != 0) {
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0';
        endLoop                  = strcmp(input, loopEndstr);
        // printf("in side the loop endloop : %d \n", endLoop);

        if (endLoop == 0) {
            printf("program is gone quit");
        } else {
            printf(" %s,\ninputlen : %lu \n", input, strlen(input));
        }
    };

    return 0;
}
