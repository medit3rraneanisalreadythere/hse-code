#include <stdio.h>
#include <stdlib.h>

int myP(int *arr, const int k)
{
    if (k == 1)
    {
        return 1;
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

    return flag;
}

int hisP(int *heap, unsigned long size)
{
    int isUp = 1, isDown=1;

    for (int i = 0; i < size; i++) {
        int pa = heap[i];
        if (2*i + 1 < size) { // left node
            int ch = heap[2*i + 1];
            if (ch > pa) isDown = 0;
            if (ch < pa) isUp = 0;
        }
        if (2*i + 2 < size) { // right node
            int ch = heap[2*i + 2];
            if (ch > pa) isDown = 0;
            if (ch < pa) isUp = 0;
        }
    }
    unsigned int ans = 0;
    ans = isUp;
    if (!isUp) {
        ans = -isDown;
    }

    return ans;
}

int main(void)
{
    for (int j = 0; j < 10000; ++j)
    {
        int k = rand() % 1000;
        int *arr = malloc(k * sizeof(int));

        for (int i = 0; i < k; ++i)
        {
            arr[i] = rand() % 1000000;
        }

        int t1 = myP(arr, k), t2 = hisP(arr, k);
        if (t1 != t2)
        {
            printf("%d\n", k);
            for (int i = 0; i < k; ++i)
            {
                printf("%d ", arr[i]);
            }
            printf("\nCorrect: %d\nMy: %d\n\n", t2, t1);
        }

        free(arr);
    }

    return 0;
}
