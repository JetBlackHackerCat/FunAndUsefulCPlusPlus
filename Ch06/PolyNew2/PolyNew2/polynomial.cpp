// This is the main project file for VC++ application project 
// generated using an Application Wizard.

// #include "stdafx.h"
#include "polynomial.h"
#include <iostream>

// #using <mscorlib.dll>

// using namespace System;
using namespace std;

// Default constructor, set polynomial to zero

polynomial::polynomial() {

		size = 1;
		coeff[0] = 0.0;

	degree = 0;
}

// Set polynomial to constand d, of degree 0
polynomial::polynomial(double d) {
//	coeff = new double __gc [1];
//	coeff = new double[1];


	// for (int i = 0; i < coeff->Length; i ++)
//	for (int i = 0; i < sizeof(coeff) / sizeof(double); i++)
//		coeff [i] = d;

	size = 1;
	coeff[0] = d;

	degree = 0;
}

// Copy constructor using array

// polynomial::polynomial (double mycoeff __gc[]) {

polynomial::polynomial(double*  mycoeff, int mysize) {

    size = mysize;
		for (int i = 0; i < mysize; i++)	
			coeff[i] = mycoeff [i];


  
	degree = mysize - 1;

}

// copy constructor 
polynomial::polynomial (polynomial * p) {
	// make a new polynomial a copy (by value) of p
//	double f __gc [] = new __gc [degree + 1];

//	for (int i = 0; i <= degree + 1; i ++)
//		f[i] = p->coeff [i];

	coeff = p->coeff;
	degree = p->degree;
}

// we are adding two polynomials.
// Note polynomials are listed from lowest exponent to highest power or the degree of the
// polynomial. 
// When two polynomials add, generally the sum polynomial will have the degree to the bigger
// degree of these two polynomials unless the coefficents of the highest exponent term cancel, in that 
// case, the degree will be that of the highest nonzero term or 0 if the sum is 0.
void polynomial::add (polynomial * p) {

	int d;
	int x;
//	d = Math::Max(degree, p->degree);
	d = std::fmax(degree, p->degree);
	
	// allocate a new polynomial newpoly of higher degree of both
	if (degree < p->degree) {
	//	double newpoly __gc [] = new double __gc [p->degree+1];
		int x = p->degree;
		double * newpoly = new double[p->degree+1];  // polynomial is NOT initialized
		
		cout << "Print new poly\n";
		for (int i = 0; i <= p->degree; i++)
			newpoly[i] = 0;
	  
	
	//	 newpoly = new double[p->degree + 1];
		for (int i = 0; i <= degree; i ++)
			newpoly [i] = coeff [i];
		
		for (int i = 0; i <= p->degree; i ++)  // compute the sum
			newpoly [i] += p->coeff[i];
//  copy polynomil newpoly to coeff
		// coeff = newpoly;
		for (int i = 0; i <= p->degree; i++)
			coeff[i] = newpoly[i];
	}
	else  // degree >= p->degree
	{
		for (int i = 0; i <= p->degree; i ++)
			coeff[i] += p->coeff[i];

	}
	// compute the degree of the sum polynomial

	if (d == 0)
		degree = 0;
	else {

		if (coeff [d] == 0.0)   // Find the first nonzero 
			while (coeff [d] == 0)
				d --;

		degree = d;
	}
		
}

void polynomial::sub (polynomial * p) {
	double* r  =  new double [p->degree + 1];
	polynomial *q = new polynomial (r, p->degree+1);
		
	for (int i = 0; i <= p->degree; i ++)
		q->coeff[i] = -p->coeff[i];
   	
	polynomial::add (q);

	}

void polynomial::mulscalar (double  d) {
	for (int i = 0; i <= degree; i ++) 
		coeff [i] *= d;
}

void polynomial::mul(polynomial * p) {
	// Make a copy of current polynomial (because current coefficients are
	// used to calculate new coefficients: for example new a[0] = old a[0] * b[0]
	// new a[1] = old a[0] * new b[1] + new a[0] * old b[1]

	// Make a new polynomial of size big enough to calculate all the coefficents.

	if ((degree == 0 && coeff [0] == 0.0) ||
		(p->degree == 0 && p->coeff[0] == 0.0))

	{  // set the product to 0 polynomial and return if one is zero.
		degree = 0;
		coeff [0] = 0.0;
		return;
	}


	int d;

	d = degree + p->degree;  // The degree of product polynomial is
	                         // equal to the sum of degrees of two polynomials

	double * product   = new double  [d + 1];
	double*  copy   = new double  [d + 1];
	double* copy2 = new double  [d + 1];

	// initialize these three arrays all to zeros
	for (int i = 0; i <= d; i++)
	{
		product[i] = 0.0;
		copy[i] = 0.0;
		copy2[i] = 0.0;
	}

	for (int i = 0; i <= degree; i ++)
		copy[i] = coeff[i];  // copy this to copy polynomial

	for (int i = 0; i <= p->degree; i ++)
		copy2[i] = p->coeff[i];

	for (int i = 0; i <= d; i ++)  // Calculate the product
	{
		product [i] = 0.0;
		for (int j = 0; j <= i; j ++)
			product [i] += copy[j]*copy2[i-j];
	}

	// copy the product to the coefficient
	// coeff = product;
	for (int i = 0; i <= d; i++)
		coeff[i] = product[i];

	degree = d;

}

polynomial * polynomial::div (polynomial * divisor) {
// Current polynomial will be divided by the divisor with quotient computed and
// remainder as second parameter

	double f  [] = {0.0};
	polynomial * rem;
	polynomial * zero = new polynomial (f, 1);


	if (divisor->degree == 0 && divisor->coeff[0] == 0.0)
	{
		// Console::WriteLine (S"Divide by zero polynomial");
		cout << "Divide by zero polynomial\n";
		rem = this;
		rem->print();
	//	return -1;
		return rem;
	}
	else
	{
		if (degree < divisor->degree)  // quotient = 0; remainder = divisor
		{
	//		polynomial *p = new polynomial (this);
		//	double f __gc [] = new double __gc [degree + 1];
			double* f = new double[degree + 1];
			polynomial *p = new polynomial (f, degree + 1);
	
			p->degree = degree;

			for (int i = 0; i <= degree; i ++)
				p->coeff[i] = coeff[i];

			// Console::WriteLine (S"Zero quotient");
			cout << "Zero quotient\n";
			this->degree = 0;
			this->coeff[0] = 0.0;
			rem = p;
			rem->print();

	//		return 1;
			return rem;

		}
		else  // Do the division A(x) = Div(x) Q(x) + R(x) with deg (R(X)) < deg (Div(X))
			  // unless Div(x) is nonzero constant, in that case A(x) = Div * A(x) / Div
			  // so Q(x) = A(x) / Div, R(x) = 0
		{
			if (divisor->degree == 0)  // divisor is nonzero constant
			{
			//	Console::WriteLine (S"Divide by constant");
				cout << "Divide by constant" << endl;
				for (int i = 0; i <= degree; i ++)
					coeff[i] /= divisor->coeff[0];
				// remainder rem is 0
			//	double g __gc []= {0.0};
				double g = { 0.0 };
				polynomial *p = new polynomial (g);
				rem = p;
				rem->print();
		//		return 2;
				return rem;
			}
			else   // divisor degree > 0.
			{
				int d = degree - divisor->degree;  // compute the degree of quotient
               
				double* q   = new double [d+1];  // allocate quotient polynomial
				double* copy  = new double  [degree +1];
		//		double cal __gc [] = new double __gc [degree];

				for (int i = 0; i <= degree; i ++)  // make a copy for calculation purpose
					copy [i] = coeff [i];

	 /*****************************************************************************
	 *                                                                            *
	 *                                  a[n]/b[m]x^n-m + a'[n-1]/b[m]x^n-m-1+.....*               
	 * b[m]x^m+b[m-1]x^m-1+... + b[0] ) a[n]x^n        + a[n-1]x^n-1 +..          *
	 *                                  a[n]x^n        + a[n]/b[m]b[m-1]x^n-1+... *                                                                           
	 *                                                                            *
	 *                                  ----------------------------------------                                                                       *
	 *                                     0           + a'[n-1]x^n-1 +  a'[n-2]x^n-2                                       *
	 *                                                                            *
	 *                                                                            *
	 *                                                                            *
	 *****************************************************************************/
				for (int i = d; i >= 0 ; i --) // compute quotient from highest exponent
				{
					q[i] = copy [divisor->degree + i] / divisor->coeff[divisor->degree];

					// update the coefficients of copy polynomial

		//			for (int k = i + divisor->degree; k >= i ; k --) {
					for (int k = i; k <= i + divisor->degree; k ++) {

						copy [k] = copy [k] - copy [i + divisor->degree] / divisor->coeff[divisor->degree] 
						           * divisor ->coeff [k - i];

				//	    cout << "subtracted item is ";
				//	    cout << copy [i + divisor->degree] / divisor->coeff[divisor->degree] 
				//		           * divisor ->coeff [k - i] << endl;

					}  // end of inner for loop k
				}  // end of for loop i = d down to i = 0

				// remainder has coefficients copy [m-1] , ..., copy [0]
				// where m = degree of divisor
				double* f  = new double  [divisor->degree+1];
				rem = new polynomial (f, divisor->degree + 1);

				for (int i = divisor->degree; i >= 0; i --)
					rem->coeff[i] = copy [i];

				this->coeff = q;  // copy quotient to this
				this->degree = d;

				// compute the degree of remainder

				int m;
				m = rem->degree;  // m >= 0 and rem != 0.0
				if (rem->coeff[m] == 0.0)
				{
					while (rem->coeff[m] == 0 && m >= 1)
					{
							m --;
					}
					rem->degree = m;
				}

				return rem;
			}  // end of innermost else 
		} // end of middle else
	} // end of outside else

}
void polynomial::print () {  // print a polynomial in the form a0 + a1x + a2x^2 + ...
	// Console::Write ("Polynomial: ");
	cout << "Polynomial: "; 
	for (int i = 0; i <= degree; i++)
		if (i == 0)
		{
			if (degree > 0)
				// Console::Write (S"\t{0}  +", coeff[i].ToString());
			{
	
				cout << "\t";
				cout << coeff[0];
				cout << " +";
	
			}
				
			
				// cout << "hello";
			else
				// Console::Write (S"\t{0}  ", coeff[i].ToString());
				cout << " " << coeff[i];
		}
		else if (i == 1 && degree > 1) {
			if (coeff[1] != 1 && coeff[1] != -1)
				// Console::Write (S"\t{0}x  +", coeff[i].ToString());
				//cout << "\tcoeff[i].ToString()" << "x  +";
				cout << " " << coeff[1] << "x  +";
			else
				if (coeff[1] == 1)
					// Console::Write (S"\tx  +");
					cout << " x +";
				else  // coeff[1] == -1
					// Console::Write (S"\t-x +");
					cout << " -x +";


		}
		else if (i == 1 && degree == 1) {
			if (coeff[i] != 1 && coeff[1] != -1)
				// Console::Write (S"\t{0}x", coeff[i].ToString());
				cout << "\t" << coeff[i] << "x";
			else
				if (coeff[1] == 1)

					cout << " x";
				else

					cout << " -x";
		}
		else if (i < degree)
			// Console::Write (S"\t{0}x^{1}  +", coeff[i].ToString(), i.ToString());
			cout << "\t" << coeff[i] << " x^ " << i << " +";

		else
			// Console::Write (S"\t{0}x^{1}  \n", coeff[i].ToString(), i.ToString());
			cout << "\t" << coeff[i] << "x^" << i << endl;
		// Console::WriteLine();
		cout << endl;
}

/*
int _tmain()
{
    // TODO: Please replace the sample code below with your own.
    Console::WriteLine(S"Hello World");
	return 0;
}
*/