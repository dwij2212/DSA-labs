#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    for (int i = 0; i < argc; i++)
    {
        printf("%s ", argv[i]);

        // condition to check if given cmd line arg is integer or not
        // done by checking each character of that cmd line arg
        int flag = 0;
        char ch;
        for (int j = 0; j < strlen(argv[i]); j++)
        {
            ch = argv[i][j];
            if (!isdigit(ch))
            {
                flag = 1;
            }
        }

        if (!flag)
        {
            printf("\n Number encountered: %d \n", atoi(argv[i]));
        }
    }
}
