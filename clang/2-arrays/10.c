#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
  int n = 0;
  scanf("%d", &n);

  double *s = malloc(n * sizeof(double));
  for (int i = 0; i < n; ++i)
  {
    scanf("%lf", &s[i]);
  }

  double answ = 0, a = 0, v = 0;
  for (int i = 0; i < n; ++i)
  {
    scanf("%lf", &a);

    if (fabs(a - 0.0) < 1e-7)
    {
      answ += (s[i] / v);
      continue;
    }

    double t = 0;
    if (i == 0)
    {
      t = sqrt(2.0 * s[i] / a);
      v = a * t;
    }
    else
    {
      double t1 = (-v + sqrt(v * v + 2.0 * a * s[i])) / a;
      double t2 = (-v - sqrt(v * v + 2.0 * a * s[i])) / a;
      if (t1 > 0)
      {
        if (t2 > 0 && t2 < t1)
        {
          t = t2;
        }
        else
        {
          t = t1;
        }
      }
      else
      {
        t = t2;
      }
      v += a * t;
    }

    answ += t;
  }

  printf("%.4lf", answ);

  free(s);

  return 0;
}
