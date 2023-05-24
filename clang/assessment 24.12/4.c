#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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
    char c;
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

void print(const struct string obj)
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
    struct string str;
    init(&str, 0);

    getString(&str);

    int part = str.length / 7;

    struct string new_str;
    init(&new_str, 6 * part);

    for (int i = 0; i < 6; ++i)
    {
        int num = 0;
        scanf("%d", &num);

        for (int j = (num - 1) * part; j < num * part; ++j)
        {
            new_str.arr[i * part + j - (num - 1) * part] = str.arr[j];
        }
    }

    print(new_str);

    deinit(&str);
    deinit(&new_str);

    return 0;
}
