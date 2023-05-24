#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h>
#include <string.h>

int num_digits(int x) // здесь может быть long long x, не совсем чётко задано условие размерности входных данных
{
    int cnt = 0;

    if (x < 0)
    {
        x *= -1;
    }

    while (x > 0)
    {
        x /= 10;
        cnt++;
    }

    return (cnt ? cnt : 1);
}

char * add_zeros(const char * str, int n)
{
    char * new_str = NULL;
    int j = 0;

    for (int i = 0; i < strlen(str); ++i) // неизвестна длина строки, конструкция if (str[i]) //вроде// работает
    {
        if (str[i] == ' ' || str[i] == '\t')
        {
            new_str = realloc(new_str, (j + 1) * sizeof(char));
            new_str[j] = str[i];
            j++;
        }

        else
        {
            int l = 0;

            for (int k = i; k < strlen(str) && (str[k] != ' ' && str[k] != '\t'); ++k)
            {
                l++;
            }

            if (l < n)
            {
                for (int k = 0; k < n - l; ++k)
                {
                    new_str = realloc(new_str, (j + 1) * sizeof(char));
                    new_str[j] = '0';
                    j++;
                }

                for (int k = i; k - i < l; ++k)
                {
                    new_str = realloc(new_str, (j + 1) * sizeof(char));
                    new_str[j] = str[k];
                    j++;
                }

                i += l;
            }

            else
            {
                for (int k = i; k - i < l; ++k)
                {
                    new_str = realloc(new_str, (j + 1) * sizeof(char));
                    new_str[j] = str[k];
                    j++;
                }

                i += l;
            }
        }

        j++;
    }

    return new_str;
}

float avg(float * arr, int n) // либо double, еслм точность - двойная
{
    if (arr == NULL || n == 0)
    {
        return 0;
    }

    float sum = 0.0;

    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
    }

    return (sum / (float)n);
}

int dev_digits(int a, int b)
{
    if (b == 0)
    {
        return 0;
    }

    if (b < 0)
    {
        b *= -1;
    }

    if (a < 0)
    {
        a *= -1;
    }

    while (b > 0)
    {
        if (b % 10 == 0)
        {
            return 0;
        }

        if (a % (b % 10))
        {
            return 0;
        }

        b /= 10;
    }

    return 1;
}

int main(void)
{
    printf("%d\n", num_digits(234526343)); // 9
    printf("%d\n", dev_digits(1000, 2481)); // 1
    // printf("%f\n", avg({1, 2, 3}, 3)); // 2
    printf("%s\n", add_zeros("zero zro  zeroooo     zerooo  zeroo", 6));

    return 0;
}
