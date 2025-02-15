 // Name:        Wade Perkins
 // Assignment:  3
 // Date:        02/23/2018
 //
 // Description: This program allows the user to choose and enter
 //              a desired range of iterations.
 //
 //              The iterations are used to calculate approximate
 //              values of pi for all iterations within the given
 //              range, and displays each value in a tabularized
 //              format.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int it_min = 0, it_max = 0, n = 0;
    double PI = 0;

    printf("Enter the smallest number of iterations to perform: ", it_min);
    scanf("%d", &it_min);

    printf("Enter the largest number of iterations to perform: ", it_max);
    scanf("%d", &it_max);

    printf("\n\nIterations\tApproximate Value of Pi");
    printf("\n-----------------------------------------");

    for (n = 0; n < it_max; n++)
    {
        PI += (1.0/(pow(16.0, n))) * (4.0/(8.0*n + 1.0) - 2.0/(8.0*n + 4.0) - 1.0/(8.0*n + 5.0) - 1.0/(8.0*n + 6.0));

        if ((n >= it_min - 1) && (n <= it_max))
        {
            printf("\n    %d\t\t   %.15lf", n + 1, PI);
        }

    }
return 0;
}
