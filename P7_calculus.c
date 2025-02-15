#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calculus.h"

int enter_polynomial(double **ptr)
{
    int degree = 0, i = 0;

    printf("What is the degree of your polynomial? ");
    scanf("%d", &degree);
    printf("\n");
//Validation
    while (degree <= 0)
    {
        printf("\nInvalid, please enter a degree that is greater than zero: ");
        scanf("%d", &degree);
    }
//Allocation
    *ptr = (double *)malloc((degree + 1) * sizeof(double));    //allocating memory for coefficients AND the constant

    if (*ptr == NULL)
    {
        printf("\n\n\n**Memory allocation error at 1***");
        exit(1);
    }
//Coefficients
    for (i = degree; i > 0; i--)
    {
        printf(" Please enter x^%d coefficient: ", i);
        scanf("%lf", *ptr + (degree - i));  //Reason for "degree - i": If degree is 6, for example, then
                                            //in normal polynomial format x_terms x^5-->x^1 because the
                                            //'for' loop is working backwards which means *ptr should be
                                            //filled backwards 'i' in RAM should be filled from 0-->4.
    }
//Constant
    printf(" Please enter the constant:    ");
    scanf("%lf", *ptr + degree);

    return degree;
}

void display_function_value(double *f_ptr, int degree)
{
    double x_val = 0.0, f_val = 0.0;
    int i = 0;

    printf("\nWhat is the value for 'x' in your function? ");
    scanf("%lf", &x_val);

    for (i = degree; i > 0; i--)
    {
        f_val += *(f_ptr + (degree - i)) * pow(x_val, i);   //Still working backwards, so need 'degree - i'
        //f_val += *(f_ptr + i) * pow(x_val, i);    //**Still going off of previous commented-example:
                                                    //Does NOT work because the stored values are accessed
                                                    //starting with the i = [5] element of the pointer and
                                                    //works toward the i = [0] element.
    }
    f_val += *(f_ptr + degree);     //adding the constant

    printf("\n\tf(%.2lf) = %.2lf", x_val, f_val);
    printf("\n");
}

void display_derivative(double *d_ptr, int degree)
{
    int i = 0, d_counter_1 = 0, d_counter_2 = 0;
//ORIGINAL
    printf("\n\t f(x) =");

    for (i = degree; i > 0; i--)
    {
        if ((*(d_ptr + (degree - i)) != 0) && (d_counter_1 > 0))
        {
            printf(" +");
        }

        if ((*(d_ptr + (degree - i)) != 0))
        {
            printf(" %.2lfx^%d", *(d_ptr + (degree - i)), i);
            d_counter_1++;
        }
    }

    if (*(d_ptr + (degree - i)) != 0)
    {
        printf(" + %.2lf", *(d_ptr + (degree - i)));   //printing the constant
    }

//DERIVATIVE
    printf("\n\tf'(x) =");

    for (i = degree; (i - 1) > 0; i--)
    {
        if ((*(d_ptr + (degree - i)) != 0) && (d_counter_2 > 0))
        {
            printf(" +");
        }

        if (*(d_ptr + (degree - i)) != 0)
        {
            printf(" %.2lfx^%d", i * *(d_ptr + (degree - i)), i - 1);
            d_counter_2++;
        }
    }

    if ((*(d_ptr + (degree - i)) != 0) && (d_counter_2 == 0))
    {
        printf(" %.2lf", *(d_ptr + (degree - i)));   //printing the original constant after derivation
    }
    else
        if ((*(d_ptr + (degree - i)) != 0) && (d_counter_2 > 0))
        {
            printf(" + %.2lf", *(d_ptr + (degree - i)));   //printing the original constant after derivation
        }
    printf("\n");
}

void display_integral(double *i_ptr, int degree)
{
    int i = 0, i_counter_1 = 0, i_counter_2 = 0;
//ORIGINAL
    printf("\n\tf(x) =");

    for (i = degree; i > 0; i--)
    {
        if ((*(i_ptr + (degree - i)) != 0) && (i_counter_1 > 0))
        {
            printf(" +");
        }

        if ((*(i_ptr + (degree - i)) != 0))
        {
            printf(" %.2lfx^%d", *(i_ptr + (degree - i)), i);
            i_counter_1++;
        }
    }

    if (*(i_ptr + (degree - i)) != 0)
    {
        printf(" + %.2lf", *(i_ptr + (degree - i)));   //printing the constant
    }

//INTEGRAL
    printf("\n\tF(x) =");

    for (i = degree; i > 0; i--)
    {
        if ((*(i_ptr + (degree - i)) != 0) && (i_counter_2 > 0))
        {
            printf(" +");
        }

        if ((*(i_ptr + (degree - i)) != 0))
        {
            printf(" %.2lfx^%d", *(i_ptr + (degree - i)) / (i + 1), i + 1);
            i_counter_2++;
        }
    }

    if ((*(i_ptr + (degree - i)) != 0) && (i_counter_2 == 0))
    {
        printf(" %.2lfx^1", *(i_ptr + (degree - i)));   //printing the original constant after integration
    }
    else
        if ((*(i_ptr + (degree - i)) != 0) && (i_counter_2 > 0))
        {
            printf(" + %.2lfx^1", *(i_ptr + (degree - i)));   //printing the original constant after integration
        }

    if (i_counter_2 > 0)
    {
        printf(" + C");
    }
    else
        printf(" C");
}
