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

int getString(struct string *obj)
{
    int spaces = 0;

    char c = '.';
    while (true)
    {
        scanf("%c", &c);
        if (c == '\n')
        {
            break;
        }

        if (c == ' ')
        {
            spaces++;
        }

        resize(obj, obj->length + 1);
        obj->arr[obj->length - 1] = c;
    }

    return spaces;
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
    int k = 0;
    scanf("%d\n", &k);

    struct string str;
    init(&str, 0);
    int x = getString(&str);

    int cnt = 0;
    for (int i = 0; i < str.length; ++i)
    {
        if (str.arr[i] == ' ')
        {
            for (int j = 0; j < (k - str.length) / x; ++j)
            {
                printf(" ");
            }

            if (cnt < (k - str.length) % x)
            {
                printf(" ");
            }

            cnt++;
        }

        printf("%c", str.arr[i]);
    }

    deinit(&str);

    return 0;
}
