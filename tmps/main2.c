#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

const int MAX_LEN = 10002;

int main(void)
{
    char s1[MAX_LEN], s2[MAX_LEN];
    int l1 = 0, l2 = 0;

    while (true)
    {
        char c = '.';
        scanf("%c", &c);

        if (c == '\n')
        {
            break;
        }

        s1[l1] = c;
        l1++;
    }

    while (true)
    {
        char c = '.';
        scanf("%c", &c);

        if (c == '\n')
        {
            break;
        }

        s2[l2] = c;
        l2++;
    }

    int i1 = l1 - 1, i2 = l2 - 1, cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < l1; ++i)
    {
        if (i2 < 0)
        {
            break;
        }

        if (s1[i] == s2[i2])
        {
            cnt1++;
        }

        i2--;
    }

    for (int i = 0; i < l2; ++i)
    {
        if (i1 < 0)
        {
            break;
        }

        if (s2[i] == s1[i1])
        {
            cnt1++;
        }

        i2--;
    }

    return 0;
}
