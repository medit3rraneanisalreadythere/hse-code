#include <stdio.h>

struct Tree
{
  int key;
  struct Tree *left;
  struct Tree *right;
};

// Напишите функцию int layer_size(struct Tree *root, int n),
// которая считает размер слоя (количество вершин) на глубине n в дереве.

int layer_size(struct Tree *root, int n)
{
    if (n == 1)
    {
        return 1;
    }

    int answ = 0;

    if (root->left)
    {
        answ += layer_size(root->left, n - 1);
    }

    if (root->right)
    {
        answ += layer_size(root->right, n - 1);
    }

    return answ;
}

/*
int main(void)
{
    struct Tree t[] = { {10, &t[1], &t[2]}, {3, NULL, NULL}, {23, NULL, NULL} };

    printf("%d %d %d %d", layer_size(t, 0), layer_size(t, 1), layer_size(t, 2), layer_size(t, 3));

    return 0;
}
*/
