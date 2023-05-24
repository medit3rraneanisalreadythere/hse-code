#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int n = 0;
  scanf("%d", &n);

  int *a = malloc(n * sizeof(int));

  for (int i = 0; i < n; ++i)
  {
    scanf("%d", &a[i]);
  }

  for (int i = 0; i < n; ++i)
  {
    printf("%d ", a[a[a[i] - 1] - 1]);
  }

  free(a);

  return 0;
}
