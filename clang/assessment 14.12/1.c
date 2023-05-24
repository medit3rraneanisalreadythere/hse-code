#include <stdio.h>

int f(int x)
{
    if (x > 0)
    {
        f(x - 4);
        printf("%d ", x);
        f(x - 4);
    }
}

int main(void)
{
    f(14);

    return 0;
}
