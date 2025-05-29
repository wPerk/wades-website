#ifndef CALCULUS_H_INCLUDED
#define CALCULUS_H_INCLUDED

    int enter_polynomial(double **);  //Note that you must use a pointer to a pointer for this function
                                      //Since the enter_polynomial function will allocate memory each time for the pointer,
                                      //the allocated memory should be freed prior to each call to enter_polynomial.
    void display_function_value(double *, int); //'void' does NOT (return? print?) anything
    void display_derivative(double *, int);
    void display_integral(double *, int);

#endif // CALCULUS_H_INCLUDED
