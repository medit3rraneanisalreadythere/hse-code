#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);

    long xor = 0;
    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
        xor ^= arr[i];
    }

    int bnum = 0;
    while (1)
    {
        if (xor & (1 << bnum))
        {
            break;
        }

        bnum++;
    }

    long xor0 = 0, xor1 = 0;
    for (int i = 0; i < n; ++i)
    {
        if ((1 << bnum) & arr[i])
        {
            xor1 ^= arr[i];
        }
        else
        {
            xor0 ^= arr[i];
        }
    }

    if (xor0 > xor1)
    {
        xor0 ^= xor1;
        xor1 ^= xor0;
        xor0 ^= xor1;
    }

    printf("%ld %ld", xor0, xor1);

    return 0;
}
