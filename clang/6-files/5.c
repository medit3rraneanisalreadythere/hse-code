#include <stdio.h>

int main(void)
{
    FILE *inp;
    inp = fopen("input.txt", "r");

    int a = 0;
    fscanf(inp, "%d", &a);

    long long answ = a;

    char c;

    while (fscanf(inp, "%c", &c) != EOF)
    {
        if (c == '+')
        {
            fscanf(inp, "%d", &a);
            answ += a;
        }

        if (c == '-')
        {
            fscanf(inp, "%d", &a);
            answ -= a;
        }
    }

    FILE *outp;
    outp = fopen("output.txt", "w");

    fprintf(outp, "%lld", answ);

    return 0;
}
