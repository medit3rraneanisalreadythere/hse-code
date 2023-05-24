#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//const int MAX_LEN = 10002;

struct string
{
    int length;
    char* arr;
};

void init(struct string *obj, int x)
{
    obj->length = x;
    obj->arr = malloc(obj->length * sizeof(char));
}

void resize(struct string *obj, int x)
{
    obj->length = x;
    obj->arr = realloc(obj->arr, obj->length * sizeof(char));
}

void deinit(struct string *obj)
{
    free(obj->arr);
}

void getString(struct string *obj)
{
    char c = '.';
    while (true)
    {
        scanf("%c", &c);

        if (c == '\n')
        {
            break;
        }

        resize(obj, obj->length + 1);
        obj->arr[obj->length - 1] = c;
    }
}

void reverse(struct string *obj, int l, int r)
{
    for (int i = l; i <= (l + r) / 2; ++i)
    {
        char t = obj->arr[i];
        obj->arr[i] = obj->arr[r - i + l];
        obj->arr[r - i + l] = t;
    }
}

int main(void)
{
    struct string str;
    init(&str, 0);
    getString(&str);

    if (str.length < 3)
    {
        printf("0");
        return 0;
    }

    int nums[1000] = {0};
    int k = 0;

    for (int i = 0; i < str.length - 2; ++i)
    {
        for (int j = i + 1; j < str.length - 1; ++j)
        {
            for (int r = j + 1; r < str.length; ++r)
            {
                int index = (str.arr[i] - '0') * 100 + (str.arr[j] - '0') * 10 + (str.arr[r] - '0');

                if (index < 100)
                {
                    continue;
                }

                if (!nums[index])
                {
                    nums[index]++;
                    k++;
                }
            }
        }
    }

    printf("%d", k);

    deinit(&str);

    return 0;
}
