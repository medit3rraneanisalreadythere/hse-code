#include <stdio.h>
#include <stdlib.h>

const int MAX_LEN = 1000001;

int main(void)
{
    FILE *inp;
    inp = fopen("input.txt", "r");

    char str[MAX_LEN];
    fgets(str, MAX_LEN, inp);

    int isOpen = 0;
    int l = 0;
    char *buff = malloc(l * sizeof(char));

    for (int i = 0; i < MAX_LEN; ++i)
    {
        if (str[i] == '\0' || str[i] == '\n')
        {
            break;
        }

        if (str[i] == 'a')
        {
            isOpen = 1;
            l = 1;
            buff = malloc(l * sizeof(char));
            buff[0] = 'a';
        }
        else if (str[i] == 'b')
        {
            if (isOpen)
            {
                isOpen = 0;
                printf("%sb\n", buff);
            }
        }
        else
        {
            if (isOpen)
            {
                l++;
                buff = realloc(buff, l * sizeof(char));
                buff[l - 1] = str[i];
            }
        }
    }

    free(buff);

    return 0;
}
