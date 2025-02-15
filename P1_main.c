 // Name:       Wade Perkins
 // Assignment:  1
 // Date:        02/01/2018
 //
 // Description: This program allows the user to enter the number of
 //              atoms for each element in an amino acid.
 //
 //              Then, the average weight of the total number of atoms
 //              in the molecule is calculated and displayed for the user.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int O = 0, C = 0, N = 0, S = 0, H = 0;
    double avg = 0.0;

    printf("Enter the number of oxygen atoms: ");
    scanf("%d", &O);

    printf("\nEnter the number of carbon atoms: ");
    scanf("%d", &C);

    printf("\nEnter the number of nitrogen atoms: ");
    scanf("%d", &N);

    printf("\nEnter the number of sulfur atoms: ");
    scanf("%d", &S);

    printf("\nEnter the number of hydrogen atoms: ");
    scanf("%d", &H);

    avg = ((O*15.9994) + (C*12.011) + (N*14.00674) + (S*32.066) + (H*1.00794)) / 5.0;

    printf("\nThe average molecular weight is: %lf", avg);

    return 0;
}

