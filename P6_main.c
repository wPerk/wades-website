 // Name:        Wade Perkins
 // Assignment:  6
 // Date:        04/06/2018
 //
 // Description: This program allows the user to enter a relation R on
 //              the set A = {a, b, c, d, e, f, g} which is stored in a
 //              2-dimensional array that represents M(R). It also asks
 //              the user for the number of times to take the boolean
 //              product of the provided relations.
 //
 //              Then, the program displays the matrix M(R) followed by
 //              R as a set of ordered pairs. The program also determines
 //              whether the matrix has qualities of symmetry, reflexivity,
 //              or transitivity. After receiving the path length, the
 //              boolean product is calculated and displayed as M(R^n) with
 //              "n" as the path length entered.


#include <stdio.h>
#include <stdlib.h>
#include "relations.h"

int main()
{
    int array[7][7] = {0}, n_array[7][7] = {0}, i = 0, j = 0, n = 0;
//                        int p[7][7] = {0};

    enter_elements(array);
//Matrix
    disp_array(array);
//Ordered pairs
    disp_R(array);
//Reflexivity
    if (determine_reflexivity(array) == 1)
    {
        printf("\nYour relation is reflexive.");
    }
    else
        {
            printf("\nYour relation is not reflexive.");
        }
//Symmetry
    if (determine_symmetry(array) == 1)
    {
        printf("\nYour relation is symmetric.");
    }
    else
        {
            printf("\nYour relation is not symmetric.");
        }
//Transitivity
    if (determine_transitivity(array) == 1)
    {
        printf("\nYour relation is transitive.");
    }
    else
        {
            printf("\nYour relation is not transitive.");
        }
//Boolean-product matrix
//                    printf("\n");
//
//                    boolean_product(array, array, p, 7, 7, 7);
//                    disp_array(p);

//M(R)^n
    printf("\nEnter path length: ");
    scanf("%d", &n);

    determine_m_r_n(array, n_array, n);
    disp_n_array(n_array, n);

    printf("\n\n\n");

    return 0;
}
