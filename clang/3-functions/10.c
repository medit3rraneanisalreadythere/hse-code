#include <stdio.h>

const long CHECKER = -2147483650;

long get(void)
{
    long x = CHECKER;
    scanf("%ld", &x);

    if (x != CHECKER)
    {
        return x;
    }

    char sym;
    scanf("%c", &sym);

    if (sym == '*')
    {
        return get() * get();
    }

    if (sym == '/')
    {
        return get() / get();
    }

    return 0;
}

int main(void)
{
    printf("%ld", get());

    return 0;
}
