#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int max(int a, int b)
{
  return (a > b ? a : b);
}

int main(void)
{
  int n = 0;
  scanf("%d", &n);

  double **spheres = malloc(n * sizeof(double*));
  for (int i = 0; i < n; ++i)
  {
      spheres[i] = malloc(4 * sizeof(double));
  }

  for (int i = 0; i < n; ++i)
  {
    scanf("%lf %lf %lf %lf", &spheres[i][0], &spheres[i][1], &spheres[i][2], &spheres[i][3]);
    for (int j = 0; j < i; ++j)
    {
      if (sqrt((spheres[j][0] - spheres[i][0]) * (spheres[j][0] - spheres[i][0]) + (spheres[j][1] - spheres[i][1]) * (spheres[j][1] - spheres[i][1]) + (spheres[j][2] - spheres[i][2]) * (spheres[j][2] - spheres[i][2])) <= spheres[i][3] + spheres[j][3])
      {
        printf("YES");
        return 0;
      }
    }
  }
  printf("NO");

  for (int i = 0; i < n; ++i)
  {
      free(spheres[i]);
  }
  free(spheres);

  return 0;
}
