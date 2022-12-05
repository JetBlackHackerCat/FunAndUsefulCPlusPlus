// Polynomial.h

#pragma once
//#using <mscorlib.dll>

// using namespace System;

class polynomial {
public:

	polynomial (); // default constructor
	polynomial (double); // put a constant as polynomial
	polynomial (double *, int);  // put an array as polynomial, using array address and size
	polynomial (polynomial *); // copy constructor
	void add (polynomial *); // add another polynomial
	void sub (polynomial *);
	void mulscalar (double ); // multiply by a scalar
	void mul (polynomial *);
	 
	polynomial * div (polynomial *); // divide polynomial, first parameter is 
	                                       // divisor, second parameter is remainder
	void print (); // Print polynomial

private:
	int size = 50;
	double*  coeff = new double [size]; // the coefficients of polynomial
	int degree; // the exponent of the highest nonzero term
	            // degree is 0 for constant (zero or nonzero constant) 
	            // For the zero polynomial, we also have coeff [0] == 0.0
};  // end class polynomial