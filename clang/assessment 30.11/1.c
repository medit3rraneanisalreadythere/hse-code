#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(int x)
{
  if (x < 10)
  {
    return 0;
  }

  int lst = x % 10;

  while (x > 9)
  {
    x /= 10;
  }

  if (x > lst)
  {
    return 1;
  }

  return 0;
}

int main(void)
{
  FILE *input;
  input = fopen("sequence.txt", "r");

  int x = 0;
  while (fscanf(input, "%d", &x) != EOF)
  {
    if (check(x))
    {
      printf("%d ", x);
    }
  }

  return 0;
}
