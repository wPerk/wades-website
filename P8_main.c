 // Name:        Wade Perkins
 // Assignment:  8
 // Date:        05/04/2018
 //
 // Description: This program utilizes no user input. It opens and reads a binary
 //              file, then calculates the magnitude and argument for each of the
 //              complex numbers that are processed from the file.
 //
 //              Finally, the processed information is written into a text file as
 //              a neatly formatted table. The complex numbers are displayed in the
 //              form a + bi, followed by its magnitude, then its argument - each
 //              value in its respective column.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    double real;
    double imag;
} complex;

double radians_to_degrees(double);

int main()
{
    int num_complex = 0, i = 0;
    double z_mag = 0.0, a_sqrd = 0.0, b_sqrd = 0.0, z_arg = 0.0, a = 0.0, b = 0.0;
    complex *z_ptr = NULL;
    FILE *in_file = NULL;
    FILE *out_file = NULL;

//READ FILE
    in_file = fopen("I:/csci171/complex.dat", "rb");

    if (in_file == NULL)
    {
        printf("\n\n\n***File opening error at 1***\n\n\n");
        exit(1);
    }

//WRITE FILE
    out_file = fopen("I:/csci171/complex.txt", "w");

    if (out_file == NULL)
    {
        printf("\n\n\n***File opening error at 1***\n\n\n");
        exit(1);
    }

//1. //READ INTEGER
    fread(&num_complex, sizeof(int), 1, in_file);

//2. //POINTER
    z_ptr = (complex *)malloc(num_complex * sizeof(complex));

    if (z_ptr == NULL)
    {
        printf("\n\n\n**Memory allocation error at 1***");
        exit(1);
    }

//3. //READ COMPLEX
    fread(z_ptr, sizeof(complex), num_complex, in_file);

//4. //PROCESS
//DOCUMENT
    fprintf(out_file, "Complex Number \t\tMagnitude\tArgument");
    fprintf(out_file, "\n------------------------------------------------");

    for (i = 0; i < num_complex; i++)
    {
        a_sqrd = pow((z_ptr + i)->real, 2);
        b_sqrd = pow((z_ptr + i)->imag, 2);
        z_mag = sqrt(a_sqrd + b_sqrd);

        b = (z_ptr + i)->imag;
        a = (z_ptr + i)->real;

        z_arg = radians_to_degrees(atan2(b, a));

        if ((z_ptr + i)->real >= 0.0)
            {
                if ((z_ptr + i)->imag >= 0.0)
                {
                    if (z_arg >= 0.0 && ((z_ptr + i)->imag != 0.0 || (z_ptr + i)->real != 0.0))
                        fprintf(out_file, "\n %.2lf + %.2lfi\t\t%.2lf\t\t %.2lf", (z_ptr + i)->real, (z_ptr + i)->imag, z_mag, z_arg);
                    else
                        if (z_arg <= 0.0 && ((z_ptr + i)->imag != 0.0 || (z_ptr + i)->real != 0.0))
                            fprintf(out_file, "\n %.2lf + %.2lfi\t\t%.2lf\t\t%.2lf", (z_ptr + i)->real, (z_ptr + i)->imag, z_mag, z_arg);
                    else
                        if (z_arg == 0.0 && (z_ptr + i)->imag == 0.0 && (z_ptr + i)->real == 0.0)
                            fprintf(out_file, "\n %.2lf + %.2lfi\t\t%.2lf\t\t none", (z_ptr + i)->real, (z_ptr + i)->imag, z_mag);
                }
                else
                    {
                        if (z_arg >= 0.0 && ((z_ptr + i)->imag != 0.0 || (z_ptr + i)->real != 0.0))
                            fprintf(out_file, "\n %.2lf - %.2lfi\t\t%.2lf\t\t %.2lf", (z_ptr + i)->real, fabs((z_ptr + i)->imag), z_mag, z_arg);
                        else
                            if (z_arg <= 0.0 && ((z_ptr + i)->imag != 0.0 || (z_ptr + i)->real != 0.0))
                                fprintf(out_file, "\n %.2lf - %.2lfi\t\t%.2lf\t\t%.2lf", (z_ptr + i)->real, fabs((z_ptr + i)->imag), z_mag, z_arg);
                        else
                            if (z_arg == 0.0 && (z_ptr + i)->imag == 0.0 && (z_ptr + i)->real == 0.0)
                                fprintf(out_file, "\n %.2lf + %.2lfi\t\t%.2lf\t\t none", (z_ptr + i)->real, (z_ptr + i)->imag, z_mag);
                    }
            }
        else
            if ((z_ptr + i)->real <= 0.0)
            {
                if ((z_ptr + i)->imag >= 0.0)
                {
                    if (z_arg >= 0.0 && ((z_ptr + i)->imag != 0.0 || (z_ptr + i)->real != 0.0))
                        fprintf(out_file, "\n%.2lf + %.2lfi\t\t%.2lf\t\t %.2lf", (z_ptr + i)->real, (z_ptr + i)->imag, z_mag, z_arg);
                    else
                        if (z_arg <= 0.0 && ((z_ptr + i)->imag != 0.0 || (z_ptr + i)->real != 0.0))
                            fprintf(out_file, "\n%.2lf + %.2lfi\t\t%.2lf\t\t%.2lf", (z_ptr + i)->real, (z_ptr + i)->imag, z_mag, z_arg);
                    else
                        if (z_arg == 0.0 && (z_ptr + i)->imag == 0.0 && (z_ptr + i)->real == 0.0)
                            fprintf(out_file, "\n %.2lf + %.2lfi\t\t%.2lf\t\t none", (z_ptr + i)->real, (z_ptr + i)->imag, z_mag);
                }
                else
                    {
                        if (z_arg >= 0.0 && ((z_ptr + i)->imag != 0.0 || (z_ptr + i)->real != 0.0))
                            fprintf(out_file, "\n%.2lf - %.2lfi\t\t%.2lf\t\t %.2lf", (z_ptr + i)->real, fabs((z_ptr + i)->imag), z_mag, z_arg);
                        else
                            if (z_arg <= 0.0 && ((z_ptr + i)->imag != 0.0 || (z_ptr + i)->real != 0.0))
                                fprintf(out_file, "\n%.2lf - %.2lfi\t\t%.2lf\t\t%.2lf", (z_ptr + i)->real, fabs((z_ptr + i)->imag), z_mag, z_arg);
                        else
                            if (z_arg == 0.0 && (z_ptr + i)->imag == 0.0 && (z_ptr + i)->real == 0.0)
                                fprintf(out_file, "\n %.2lf + %.2lfi\t\t%.2lf\t\t none", (z_ptr + i)->real, (z_ptr + i)->imag, z_mag);
                    }
            }
    }

    fclose(in_file);
    fclose(out_file);

    return 0;
}

double radians_to_degrees(double rad)
{
    double in_degrees = 0.0;

    in_degrees = rad * (180.0 / M_PI);

    return in_degrees;
}
