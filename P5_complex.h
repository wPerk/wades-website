#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

//Author:         Todd Simeone
//Year written:   2017
//
//Note about the complex datatype - this is a user-defined datatype
//in order to declare and access the real and imag members of the structure, the following
//syntax must be used:
//
//Declaration (same as any other datatype):
//
//     complex x;   //Declaring a variable called x which is a complex number
//
//Accessing the members:
//
//     x.real       //Will provide access to the real part of the complex number
//     x.imag       //Will provide access to the imaginary part of the complex number

typedef struct {
    double real;
    double imag;
} complex;

//Function add_complex adds two complex numbers and returns the calculated sum as a complex number
complex add_complex (complex, complex);

//Function subtract_complex subtracts the second complex parameter from the first and returns the calculated difference as a complex number
complex subtract_complex (complex, complex);

//Function multiply_complex multiplies two complex numbers and returns the calculated product as a complex number
complex multiply_complex (complex, complex);

//Function divide_complex divides the second complex parameter into the first and returns the calculated quotient as a complex number
complex divide_complex (complex, complex);

//Function pow_complex raises the complex parameter to the power indicated by the integer parameter and returns the calculated power as a complex number
complex pow_complex (complex, int);

#endif // COMPLEX_H_INCLUDED
