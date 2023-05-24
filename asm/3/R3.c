#include <stdio.h>

int main(void)
{
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);

    int a[21], b[21]; //esi edi

    int *esi = a;
    int *edi = b;

    *(esi) = 1;

    for (int ecx = 0; ecx != n; )
    {
        ecx++;

        *(edi) = 1;

        int edx = 0;
        for (; edx != ecx; )
        {
            edx++;

            *(edi + edx) = *(esi + edx) + *(esi + edx - 1);
        }

        *(edi + edx) = 1;

        int *tmp = esi;
        esi = edi;
        edi = tmp;
    }

    printf("%d", *(esi + k));

    return 0;
}
