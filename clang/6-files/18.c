#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int main(void)
{
    struct string s1, s2;
    init(&s1, 0);
    init(&s2, 0);

    getString(&s1);
    getString(&s2);

    
}
