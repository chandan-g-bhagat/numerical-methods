#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define f(x) ((x * x * x) - 18)
#define fd(x) (3 * x * x)
#define fdd(x) 6 * x
int main()
{
    float x0, x1, error, errorold, converge, order;
    int i = 0;
    printf("Input the approximation : ");
    scanf("%f", &x0);
    converge = (f(x0) * fdd(x0)) / (fd(x0) * fd(x0));
    if (converge > 1)
        exit(1);
    printf("Ite\tX0\t\tX1\t\tError\t\tOrder\n");
    do
    {
        errorold = error;
        x1 = x0 - (f(x0) / fd(x0));
        if (f(x1) == 0)
        {
            break;
        }
        error = fabs(x1 - x0);
        printf("%2d\t%4.6f\t%4.6f\t%4.6f\t", ++i, x0, x1, error);
        if (i == 1 || error == 0 || errorold == 1)
        {
            printf("-----\n");
        }
        else
        {
            order = log(error) / log(errorold);
            printf("%4.6f\n", order);
        }
        x0 = x1;
    } while (error > 0.00005);
    printf("Root is %4.6f", x0);
    return 0;
}