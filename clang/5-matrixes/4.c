#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x = 0;
    long long n = 0;
    int *data = NULL;

    while (1)
    {
        scanf("%d", &x);

        if (x == 0)
        {
            break;
        }

        n++;
        data = realloc(data, n * sizeof(int));
        data[n - 1] = x;
    }

    long long answ = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (data[i] < data[n - 1])
        {
            answ++;
        }
    }

    printf("%lld", answ);

    free(data);

    return 0;
}
