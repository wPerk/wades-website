 // Name:        Wade Perkins
 // Assignment:  5
 // Date:        03/23/2018
 //
 // Description: This program allows the user to enter a number of
 //              elements for the sequence.
 //
 //              Then the values for each element of the sequence
 //              are calculated and displayed according to both the
 //              recursive and explicit versions of the sequence.



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"

int recursive_f(int);
int explicit_f(int);

int main()
{
    int n = 0, i = 0;

    printf("\nEnter the number of sequence elements: ");
    scanf("%d", &n);

    printf("\n  Element\tRecursive\tExplicit\n-----------------------------------------");

    for (i = 1; i <= n; i++)
    {
        printf("\n    %d\t\t   %d\t\t   %d", i, recursive_f(i), explicit_f(i));
    }

    printf("\n\n\n");

    return 0;
}

int recursive_f(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
        if (n == 2)
        {
            return 4;
        }
        else
            if (n >= 3)
            {
                return 2*recursive_f(n - 1) - 2*recursive_f(n - 2);
            }
}

int explicit_f(int n)
{
    complex a, b, c, d, e;

    a.real = -0.5;
    a.imag = -1.0;

    b.real = -0.5;
    b.imag = 1.0;

    c.real = 1.0;
    c.imag = 1.0;

    d.real = 1.0;
    d.imag = -1.0;

    e = add_complex(multiply_complex(pow_complex(c, n), a), multiply_complex(pow_complex(d, n), b));

    return (int)e.real;
}
