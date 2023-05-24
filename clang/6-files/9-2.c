#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *inp;
    inp = fopen("input.bin", "rb");

    int x = 0, k = 0;
    int *arr = malloc(k * sizeof(int));

    while (fread(&x, sizeof(int), 1, inp) != 0)
    {
        k++;
        arr = realloc(arr, k * sizeof(int));
        arr[k - 1] = x;
    }

    fclose(inp);

    FILE *outp;
    outp = fopen("output.bin", "wb");

    if (k == 1)
    {
        fwrite(&k, sizeof(int), 1, outp);
        fclose(outp);
        return 0;
    }

    int flag = 0; // 1 - >=; -1 - <=; 0 - !!

    for (int i = 0; i < k; ++i)
    {
        if (k > 2 * i + 2)
        {
            if (arr[2 * i + 1] >= arr[i] && arr[2 * i + 2] >= arr[i] && flag != -1)
            {
                flag = 1;
            }

            else if (arr[2 * i + 1] <= arr[i] && arr[2 * i + 2] <= arr[i] && flag != 1)
            {
                flag = -1;
            }

            else
            {
                flag = 0;
                break;
            }
        }

        else if (k > 2 * i + 1)
        {
            if (arr[2 * i + 1] >= arr[i] && flag != -1)
            {
                flag = 1;
            }

            else if (arr[2 * i + 1] <= arr[i] && flag != 1)
            {
                flag = -1;
            }

            else
            {
                flag = 0;
            }
        }
    }

    fwrite(&flag, sizeof(int), 1, outp);

    fclose(outp);

    free(arr);

    return 0;
}
