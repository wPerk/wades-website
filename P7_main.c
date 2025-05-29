 // Name:        Wade Perkins
 // Assignment:  7
 // Date:        04/17/2018
 //
 // Description: This program initially asks the user to enter the coefficients and constant of a
 //              polynomial to a degree greater than zero. Then, the user will be allowed to choose
 //              what will be done with the polynomial by selecting one of the numbered options
 //              displayed by the program's menu. The program will continue to run until the user
 //              selects option 9 which exits the program.
 //
 //              If the user selects option 1, the program will calculate and display the value of
 //              the function. If option 2 or 3 is selected, the program will calculate the derivative
 //              or indefinite integral, respectively, and display the original along with the new
 //              polynomial function. Finally, option 4 allows the user to enter a new polynomial.


#include <stdio.h>
#include <stdlib.h>
#include "calculus.h"
#include "menu.h"

int main()
{
    double *p_ptr = NULL;
    int degree = 0, choice = 0;

    degree = enter_polynomial(&p_ptr);
    choice = display_menu(choice);

    while (choice != 9)
    {
        if (choice == 1)
        {
            display_function_value(p_ptr, degree);
            choice = display_menu(choice);
        }
        else
            if (choice == 2)
            {
                display_derivative(p_ptr, degree);
                choice = display_menu(choice);
            }
        else
            if (choice == 3)
            {
                display_integral(p_ptr, degree);
                choice = display_menu(choice);
            }
        else
            if (choice == 4)
            {
                free(p_ptr);
                printf("\n");
                degree = enter_polynomial(&p_ptr);
                choice = display_menu(choice);
            }
    }

    printf("\n\n\n");

    return 0;
}
