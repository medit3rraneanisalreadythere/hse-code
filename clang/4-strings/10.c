#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char c;
    while (true)
    {
        scanf("%c", &c);

        if (c == '\0')
        {
            break;
        }

        if (c == ' ')
        {
            break;
        }

        if (c == '\n')
        {
            break;
        }

        resize(obj, obj->length + 1);
        obj->arr[obj->length - 1] = c;
    }
}

void prefix (const struct string s, int *pi, const int n) {
	for (int i = 1; i < n; ++i)
    {
		int j = pi[i - 1];

        while (j > 0 && s.arr[i] != s.arr[j])
        {
			j = pi[j - 1];
        }

		if (s.arr[i] == s.arr[j])
        {
            ++j;
        }

		pi[i] = j;
	}
}

int main(void)
{
    struct string s1, s2;
    init(&s1, 0);
    init(&s2, 0);

    getString(&s1);
    getString(&s2);

    struct string t1, t2;
    init(&t1, s1.length + 1 + s2.length);
    init(&t2, s1.length + 1 + s2.length);

    strcat(t1.arr, s1.arr);
    strcat(t1.arr, " ");
    strcat(t1.arr, s2.arr);

    strcat(t2.arr, s2.arr);
    strcat(t2.arr, " ");
    strcat(t2.arr, s1.arr);

    int *pi1 = malloc((s1.length + 1 + s2.length) * sizeof(int));
    int *pi2 = malloc((s1.length + 1 + s2.length) * sizeof(int));

    prefix(t1, pi1, s1.length + 1 + s2.length);
    prefix(t2, pi2, s1.length + 1 + s2.length);

    printf("%d %d", pi1[s1.length + s2.length], pi2[s1.length + s2.length]);

    deinit(&s1);
    deinit(&s2);
    deinit(&t1);
    deinit(&t2);
    free(pi1);
    free(pi2);

    return 0;
}
