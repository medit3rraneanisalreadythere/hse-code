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

void shift(struct string *obj, int x)
{
    if (!x)
    {
        return;
    }

    reverse(obj, 0, x - 1);
    reverse(obj, x, obj->length - 1);
    reverse(obj, 0, obj->length - 1);
}

void print(struct string obj)
{
    for (int i = 0; i < obj.length; ++i)
    {
        if ((obj.arr[i] >= 'A' && obj.arr[i] <= 'Z') || (obj.arr[i] >= 'a' && obj.arr[i] <= 'z')) {
            printf("%c", obj.arr[i]);
        }
    }
}

int main(void)
{
    int n = 0;
    scanf("%d\n", &n);

    struct string str;
    init(&str, 0);
    getString(&str);

    shift(&str, n % str.length);

    print(str);

    deinit(&str);

    return 0;
}
