#include "relations.h"

int enter_elements(int array[7][7])
{
    int elmnt_num = 0;
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0;
    char letter = 0;

    printf("How many elements is 'a' related to?: ");
    scanf("%d", &a);
    for (elmnt_num = 1; elmnt_num <= a; elmnt_num++)
    {
        printf("Enter relationship %d for a: ", elmnt_num);
        scanf(" %c", &letter);

        array[0][convert_char(letter)] = 1;
    }

    printf("\nHow many elements is 'b' related to?: ");
    scanf("%d", &b);
    for (elmnt_num = 1; elmnt_num <= b; elmnt_num++)
    {
        printf("Enter relationship %d for b: ", elmnt_num);
        scanf(" %c", &letter);

        array[1][convert_char(letter)] = 1;
    }

    printf("\nHow many elements is 'c' related to?: ");
    scanf("%d", &c);
    for (elmnt_num = 1; elmnt_num <= c; elmnt_num++)
    {
        printf("Enter relationship %d for c: ", elmnt_num);
        scanf(" %c", &letter);

        array[2][convert_char(letter)] = 1;
    }

    printf("\nHow many elements is 'd' related to?: ");
    scanf("%d", &d);
    for (elmnt_num = 1; elmnt_num <= d; elmnt_num++)
    {
        printf("Enter relationship %d for d: ", elmnt_num);
        scanf(" %c", &letter);

        array[3][convert_char(letter)] = 1;
    }

    printf("\nHow many elements is 'e' related to?: ");
    scanf("%d", &e);
    for (elmnt_num = 1; elmnt_num <= e; elmnt_num++)
    {
        printf("Enter relationship %d for e: ", elmnt_num);
        scanf(" %c", &letter);

        array[4][convert_char(letter)] = 1;
    }

    printf("\nHow many elements is 'f' related to?: ");
    scanf("%d", &f);
    for (elmnt_num = 1; elmnt_num <= f; elmnt_num++)
    {
        printf("Enter relationship %d for f: ", elmnt_num);
        scanf(" %c", &letter);

        array[5][convert_char(letter)] = 1;
    }

    printf("\nHow many elements is 'g' related to?: ");
    scanf("%d", &g);
    for (elmnt_num = 1; elmnt_num <= g; elmnt_num++)
    {
        printf("Enter relationship %d for g: ", elmnt_num);
        scanf(" %c", &letter);

        array[6][convert_char(letter)] = 1;
    }
}

int disp_array(int array[7][7])
{
        int i = 0, j = 0;

        printf("\nM(R)\n-------------\n");

        for (i = 0; i < 7; i++)
        {
            for (j = 0; j < 7; j++)
            {
                printf("%d ", array[i][j]);
            }
            printf("\n");
        }
}

int disp_R(int array[7][7])
{
        int i = 0, j = 0;
        char flag = 'N';

        printf("\n");

        printf("R = {");

        for (i = 0; i < 7; i++)
        {
            for (j = 0; j < 7; j++)
            {
                if (flag == 'Y' && array[i][j] == 1)
                {
                    printf(", ");
                }
                if (array[i][j] == 1)
                {
                    printf("(%c, %c)", convert_index(i), convert_index(j));
                    flag = 'Y';
                }
            }
        }

        printf("}");
}

int convert_char(char letter)    //CHAR-->INDEX
{
    switch (letter)
    {
        case 'a':
            return 0;
            break;

        case 'b':
            return 1;
            break;

        case 'c':
            return 2;
            break;

        case 'd':
            return 3;
            break;

        case 'e':
            return 4;
            break;

        case 'f':
            return 5;
            break;

        case 'g':
            return 6;
            break;
    }
}

int convert_index(int val)  //INDEX-->CHAR
{
    switch (val)
    {
        case 0:
            return 'a';
            break;

        case 1:
            return 'b';
            break;

        case 2:
            return 'c';
            break;

        case 3:
            return 'd';
            break;

        case 4:
            return 'e';
            break;

        case 5:
            return 'f';
            break;

        case 6:
            return 'g';
            break;
    }
}

int determine_reflexivity(int array[7][7]) //Does NOT print anything
{
    int i = 0;

    for (i = 0; i < 7; i++)
    {
        if (array[i][i] == 0)
        {
          return 0;
        }
    }

    return 1;
}
//***Note:  R is reflexive iff ALL of the diagonal elements of M(R) are 1.

int determine_symmetry(int array[7][7]) //Does NOT print anything
{
    int i = 0, j = 0;

    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            if(array[i][j] != array[j][i])
            {
                return 0;
            }
        }
    }

    return 1;
}
//***Note:  R is symmetric iff M(R) = M(R)^T

int determine_transitivity(int array[7][7]) //Does NOT print anything
{
    int i = 0, j = 0, p[7][7] = {0};

    boolean_product(array, array, p, 7, 7, 7);

    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            if ((p[i][j] == 1) && (array[i][j] != 1))
            {
                return 0;
            }
        }
    }

    return 1;
}
//***Note:  R is transitive if M(R) has a 1 everywhere the boolean product of M(R) with itself has a 1 (the converse need not be true).

//boolean_product parameter definitions
//----------------------------------------------
//m1 is the first matrix in the boolean product
//m2 is the second matrix in the boolean product
//p will store the boolean product
//m1_row is the number of rows in the first matrix
//mid is the number of columns in the first matrix (this will be equal to the number of rows in the second matrix)
//m2_col is the number of columns in the second matrix
void boolean_product(int m1[7][7], int m2[7][7], int p[7][7], int m1_row, int mid, int m2_col)
{
	int i = 0, j = 0, c = 0, current_element = 0;

	for (i = 0; i < m1_row; i++)
    {
		for (j = 0; j < m2_col; j++)
		{
			for (c = 0; c < mid; c++)
			{
				if ((m1[i][c] == 1) && (m2[c][j] == 1))
				{
					current_element = 1;
				}
			}

			p[i][j] = current_element;
			current_element = 0;    //sets both back to 0 for next iteration?
		}
	}
}

//Calculate & store M(R^n) in the 2nd parameter
//This function will utilize 'copy matrix'
void determine_m_r_n(int array[7][7], int n_array[7][7], int n) //'void' because it doesn't return anything
{
    int i = 0, j = 0, p[7][7] = {0};

    ctrl_c(array, p);   //copy array into p
    boolean_product(array, p, n_array, 7, 7, 7);

    for (i = 2; i < n; i++)
    {
        ctrl_c(n_array, p);
        boolean_product(array, p, n_array, 7, 7, 7);
    }
}

//Displays M(R)^n
int disp_n_array(int n_array[7][7], int n)
{
        int i = 0, j = 0;

        printf("\nM(R^%d)\n-------------\n", n);

        for (i = 0; i < 7; i++)
        {
            for (j = 0; j < 7; j++)
            {
                printf("%d ", n_array[i][j]);
            }
            printf("\n");
        }
}

int ctrl_c(int source[7][7], int dest[7][7])    //Copies matrix
{
    int i = 0, j = 0;

    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            dest[i][j] = source[i][j];
        }
    }
}
