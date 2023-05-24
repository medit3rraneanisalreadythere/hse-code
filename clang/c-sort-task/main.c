#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/*
1. Тип = double
2. less or equal
3. метод простого выбора, метод Шелла
*/

void generate_array(const int n, double *a, int type)
{
/*
• элементы уже упорядочены (1);
• элементы упорядочены в обратном порядке (2);
• расстановка элементов случайна (3, 4).
*/
    srand(time(NULL));

    a[0] = (double)rand() / RAND_MAX * (RAND_MAX - 1.0) + 1.0;

    if (type == 1) // less or equal
    {
        for (int i = 1; i < n; ++i)
        {
            a[i] = (double)rand() / RAND_MAX * (a[i - 1] - 1.0) + 1.0;
        }
    }

    if (type == 2) // greater or equal
    {
        for (int i = 1; i < n; ++i)
        {
            a[i] = (double)rand() / RAND_MAX * (RAND_MAX - a[i - 1]) + a[i - 1];
        }
    }

    if (type == 3 || type == 4)
    {
        for (int i = 1; i < n; ++i)
        {
            a[i] = (double)rand() / RAND_MAX * (RAND_MAX - 1.0) + 1.0;
        }
    }
}

void sort1(const int n, double *a);
void sort2(const int n, double *a);

bool check(double *source, double *sorted, const int n);



signed main(void)
{
    int n = 1;
    scanf("%d", &n);

    double *a = malloc(n * sizeof(double));

    

    return 0;
}
