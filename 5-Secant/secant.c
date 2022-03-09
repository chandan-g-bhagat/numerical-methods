#include <stdio.h>
#include <math.h>
#define f(x) (pow(x, 3) - 18)
int main()
{
    float x0, x1, x2, error;
    int i = 0;
    printf("Input Two Approximations: ");
    scanf("%f %f", &x0, &x1);
    printf("Ite\tX0\t\tX1\t\tf(X0)\t\tf(X1)\t\tError\n");
    do
    {
        x2 = ((x0 * f(x1)) - ((x1)*f(x0))) / ((f(x1) - f(x0)));
        printf("%2d\t%4.6f\t%4.6f\t%4.6f\t%4.6f\t%4.6f\n", i++, x0, x1, f(x0), f(x1), error);
        error = fabs((x2) - (x1));
        x0 = x1;
        x1 = x2;
    } while (error > 0.00005);
    return 0;
}