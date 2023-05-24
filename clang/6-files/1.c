#include <stdio.h>

int isLetter(const char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    {
        return 1;
    }

    return 0;
}

const int MAX_LEN = 20001;

int main(void)
{
    FILE *inp;
    inp = fopen("input.txt", "r");

    char str[MAX_LEN];
    int wasEmpty = 1, wasDash = 0;
    long long w = 0, s = 0, p = 0;

    while (fgets(str, MAX_LEN, inp) != NULL)
    {
        int isEmpty = 1;

        for (int i = 0; str[i] != '\n'; ++i)
        {
            if (str[i] == '.')
            {
                s++;
            }

            int t = isLetter(str[i]);

            if (t && isEmpty)
            {
                isEmpty = 0;

                if (wasDash) {
                    wasDash = 0;
                }
                else
                {
                    w++;
                }
            }
            else if (t && (str[i - 1] == ' ' || str[i - 1] == '.'))
            {
                w++;
            }
            else if (t)
            {
                if (wasDash)
                {
                    wasDash = 0;
                }
            }

            if (str[i] == '-')
            {
                wasDash = 1;
            }
        }

        if (!isEmpty && wasEmpty)
        {
            p++;
        }

        wasEmpty = isEmpty;
    }

    FILE *outp;
    outp = fopen("output.txt", "w");

    fprintf(outp, "%lld %lld %lld", w, s, p);

    return 0;
}
