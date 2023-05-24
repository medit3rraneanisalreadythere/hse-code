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

  int m = 0;
  scanf("%d", &m);

  long *answ = malloc(m * sizeof(long));
  for (int i = 0; i < m; ++i)
  {
    long x = 0, p = 1;
    scanf("%ld", &x);
    for (int j = 0; j < n; ++j)
    {
      answ[m - 1 - i] += (a[j] * p);
      p *= x;
    }
  }

  for (int i = 0; i < m; ++i)
  {
    printf("%ld ", answ[i]);
  }

  free(a);
  free(answ);
  
  return 0;
}
