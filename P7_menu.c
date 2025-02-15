#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "menu.h"

int display_menu(int choice)
{
    printf("\n\nYou may select one of the following options.\n");
    printf("\n 1.Display a function value");
    printf("\n 2.Display the polynomial's derivative");
    printf("\n 3.Display the polynomial's indefinite integral");
    printf("\n 4.Enter a new polynomial");
    printf("\n 9.Exit");

    printf("\n\n Enter selection: ");
    scanf("%d", &choice);

    while ((choice < 1) || (choice > 4) && (choice != 9))
    {
        printf(" Invalid selection, please try again: ");
        scanf("%d", &choice);
    }

    return choice;
}
