#include "complex.h"

complex add_complex (complex x, complex y) {
    complex sum;

    sum.real = x.real + y.real;
    sum.imag = x.imag + y.imag;

    return sum;
}

complex subtract_complex (complex x, complex y) {
    complex difference;

    difference.real = x.real - y.real;
    difference.imag = x.imag - y.imag;

    return difference;
}

complex multiply_complex (complex x, complex y) {
    complex product;

    product.real = x.real * y.real - x.imag * y.imag;
    product.imag = x.real * y.imag + x.imag * y.real;

    return product;
}

complex divide_complex (complex x, complex y) {
    complex quotient;

    quotient.real = (x.real * y.real + x.imag * y.imag) / (y.real * y.real + y.imag * y.imag);
    quotient.imag = (x.imag * y.real - x.real * y.imag) / (y.real * y.real + y.imag * y.imag);

    return quotient;
}

complex pow_complex (complex base, int exp) {
    complex power = base;
    int i = 2;

    for (; i <= exp; i++)
        power = multiply_complex(base, power);

    return power;
}
