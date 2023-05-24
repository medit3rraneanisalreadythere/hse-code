#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x = 0;
    scanf("%d", &x);

    char *s1 = malloc(x * sizeof(char));
    char *s2 = malloc(x * sizeof(char));
    char *s3 = malloc(x * sizeof(char));

    int i = 0;
    while (i < x)
    {
        char c;
        scanf("%c", &c);

        if (c >= 'a' && c <= 'z')
        {
            s1[i] = c;
            i++;
        }
    }

    i = 0;
    while (i < x)
    {
        char c;
        scanf("%c", &c);

        if (c >= 'a' && c <= 'z')
        {
            s2[i] = c;
            i++;
        }
    }

    i = 0;
    while (i < x)
    {
        char c;
        scanf("%c", &c);

        if (c >= 'a' && c <= 'z')
        {
            s3[i] = c;
            i++;
        }
    }

    for (int i = 0; i < x; ++i)
    {
        printf("%c", s3[i]);
    }

    for (int i = 0; i < x; ++i)
    {
        printf("%c", s1[i]);
    }

    for (int i = 0; i < x; ++i)
    {
        printf("%c", s2[i]);
    }

    free(s1);
    free(s2);
    free(s3);

    return 0;
}
