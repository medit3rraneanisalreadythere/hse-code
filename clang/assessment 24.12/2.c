#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // const char *b = "rest";
    // const char i[] = "stare";

    const char b[] = "restare";
    char p = '2';
    const char *i = &b[2];

    /*
    for (int j = 0; j < 256; ++j)
    {
        char p = j;
        if (i == p - '0' + b)
        {
            printf("%c\n", p);
        }
    }
    */

    printf("%d\n", (!(strcmp(i, "stare") | memcmp(b, "rest", 4))));
    printf("%d\n", (sizeof b < 9));
    printf("%d\n", (i == p - '0' + b));

    return 0;
}
