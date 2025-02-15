 // Name:        Wade Perkins
 // Assignment:  2
 // Date:        02/09/2018
 //
 // Description: This program allows the user to enter any value
 //              for each term in a quadratic equation.
 //
 //              The roots are determined to be real, double, or
 //              complex; then are calculated and presented to
 //              the user.


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a = 0, b = 0, c = 0;
    float x_1 = 0.0, x_2 = 0.0;
    float complex = 0, discriminant = 0;

    printf("Enter the coefficient of the quadratic term: ");
    scanf("%d", &a);

    printf("\nEnter the coefficient of the linear term: ");
    scanf("%d", &b);

    printf("\nEnter the constant: ");
    scanf("%d", &c);

    discriminant = (b*b - 4.0*a*c);

    if (discriminant > 0)
    {
        x_1 = (-1.0*b + sqrt(b*b - 4.0*a*c)) / 2*a;
        x_2 = (-1.0*b - sqrt(b*b - 4.0*a*c)) / 2*a;

        printf("\nThe two real roots for this quadratic are: %.2lf and %.2lf", x_1, x_2);
    }
        else
            if (discriminant == 0)
            {
                x_1 = (-1.0*b + sqrt(b*b - 4.0*a*c)) / 2*a;
                x_2 = (-1.0*b - sqrt(b*b - 4.0*a*c)) / 2*a;

                printf("\nThe double root for this quadratic is: %.2lf", x_1);
            }
                else
                    if (discriminant < 0)
                    {
                        x_1 = ((-1.0*b) / 2*a), sqrt(4.0*a*c - b*b) / 2*a;
                        x_2 = ((-1.0*b) / 2*a), sqrt(4.0*a*c - b*b) / 2*a;

                        complex = sqrt(-(b*b - 4.0*a*c)) / (2 * a);

                        printf("\nThe two complex roots for this quadratic are: \n(%.2f + %.2fi) and (%.2f - %.2fi)\n",
                        x_1, complex, x_2, complex);
                    }

    return 0;
}
