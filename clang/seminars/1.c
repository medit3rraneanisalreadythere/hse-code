#include <stdio.h>

// typedef <object> <type_name>
typedef struct list_t
{
    short key; // 2 байта
    struct list_t *next; // 4 байта
} list;

// list *t <- указатель на верхушку списка
void readList(list *t)
{
    int n = 0;
    scanf("%d", &n);

    short a = 0;
    list *p = t;
    for (int i = 0; i < n; ++i)
    {
        scanf("%hd", &a);
        p->key = a;
        p = p->next;
    }
}

int main(void)
{
    return 0;
}
