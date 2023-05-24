#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);

    int **answ = NULL;
    long mxs = 0;
    int idx = 0;

    for (int k = 0; k < n; ++k)
    {
        int m = 0;
        scanf("%d", &m);

        long s = 0;

        int **a = malloc(m * sizeof(int*));
        for (int i = 0; i < m; ++i)
        {
            a[i] = malloc(m * sizeof(int));
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                scanf("%d", &a[i][j]);
                if (i == j)
                {
                    s += a[i][j];
                }
            }
        }

        if (s > mxs)
        {
            mxs = s;
            answ = a;
            idx = m;
        }
    }

    for (int i = 0; i < idx; ++i)
    {
        for (int j = 0; j < idx; ++j)
        {
            printf("%d ", answ[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < idx; ++i)
    {
        free(answ[i]);
    }
    free(answ);

    return 0;
}
