// Solution of bisection method
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define f(x) ((x * x * x) - (2 * x) - 5)
int main()
{
  float a = 0, b = 0, error = 0, m, mold;
  int i = 0;
  printf("Input Interval: ");
  scanf("%f,%f", &a, &b);
  if ((f(a) * f(b)) > 0)
  {
    printf("Invalid Interval Exit!"); // to test whether search interval
    exit(1);                          // is okay or not
  }
  else if (f(a) == 0 || f(b) == 0)
  {
    printf("Root is one of interval bounds. Root is %f\n", f(a) == 0 ? a : b);
    exit(0);
  }
  printf("Ite\ta\t\tb\t\tm\t\tf(m)\t\terror\n");
  do
  {
    mold = m;
    m = (a + b) / 2;
    printf("%2d\t%4.6f\t%4.6f\t%4.6f\t%4.6f\t", i++, a, b, m, f(m));
    if (f(m) == 0)
    {
      printf("Root is %4.6f\n", m);
    }
    else if ((f(a) * f(m)) < 0)
    {
      b = m;
    }
    else
      a = m;
    error = fabs(m - mold);
    if (i == 1)
    {
      printf("----\n");
    }
    else
      printf("%4.6f\n", error);
  } while (error > 0.00005);
  printf("Approximate Root is %4.6f", m);
  return 0;
}