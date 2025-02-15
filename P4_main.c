 // Name:        Wade Perkins
 // Assignment:  4
 // Date:        03/05/2018
 //
 // Description: This program allows the user to enter the degree,
 //              coefficients, and constant of a cubic polynomial
 //              along with the upper and lower limits of integration.
 //
 //              Then, the value of the integrated polynomial is
 //              calculated and displayed, along with the polynomial
 //              formatted as an integral, to the user.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int get_degree();
double di_max_degree_3(double, double, double, double, double, double);
double fv_max_degree_4(double, double, double, double, double, double);

int main()
{
    double a = 0.0, b = 0.0, c = 0.0, C = 0.0;
    double l = 0.0, u = 0.0;

    printf("Calculation of simple definite integrals\n----------------------------------------\n\n");

    int deg = get_degree();

    if (deg == 3)
    {
        printf("Enter the coefficient of x^3:  ");
        scanf("%lf", &a);
    }
        if (deg >= 2)
        {
            printf("Enter the coefficient of x^2:  ");
            scanf("%lf", &b);
        }
            if (deg >= 1)
            {
                printf("Enter the coefficient of x:    ");
                scanf("%lf", &c);
            }

    printf("Enter the constant:            ");
    scanf("%lf", &C);

    printf("\nEnter the lower limit of integration:  ");
    scanf("%lf", &l);
    printf("Enter the upper limit of integration:  ");
    scanf("%lf", &u);

    if (deg == 3)
    {
        printf("\n%c\n%c%.2lfx^3 + %.2lfx^2 + %.2lfx + %.2lf from %.2lf to %.2lf is: %.2lf\n\n\n", 244, 245, a, b, c, C, l, u, di_max_degree_3(a, b, c, C, l, u));
    }
    else
        if (deg == 2)
        {
            printf("\n%c\n%c%.2lfx^2 + %.2lfx + %.2lf from %.2lf to %.2lf is: %.2lf\n\n\n", 244, 245, b, c, C, l, u, di_max_degree_3(a, b, c, C, l, u));
        }
        else
            if (deg == 1)
            {
                printf("\n%c\n%c%.2lfx + %.2lf from %.2lf to %.2lf is: %.2lf\n\n\n", 244, 245, c, C, l, u, di_max_degree_3(a, b, c, C, l, u));
            }
            else
                if (deg == 0)
                {
                    printf("\n%c\n%c%.2lf from %.2lf to %.2lf is: %.2lf\n\n\n", 244, 245, C, l, u, di_max_degree_3(a, b, c, C, l, u));
                }

}

int get_degree()
{
    int deg = 0;

    printf("What is the degree of your polynomial (max degree accepted is 3): ");
    scanf("%d", &deg);

    while((deg < 0) || (deg > 3))
    {
        printf("Invalid entry, the degree must be between 0 and 3: ");
        scanf("%d", &deg);
    }
    printf("\n");

    return deg;
}

double di_max_degree_3(double a, double b, double c, double C, double l, double u)
{
    return fv_max_degree_4(a/4.0, b/3.0, c/2.0, C, 0, u) - fv_max_degree_4(a/4.0, b/3.0, c/2.0, C, 0, l);
}

double fv_max_degree_4(double a, double b, double c, double C, double constant, double x)
{
    return a*pow(x, 4) + b*pow(x, 3) + c*pow(x, 2) + C*x + 0;
}
