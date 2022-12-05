#include "polynomial.h"
#include <iostream>
using namespace std;

int main () {

	

//	double f __gc [] = {1, 1};  // f(x) = 1 + 2.1x + 3.0 x^2 + 3x^3
	double f [] = { 1, 1 };  // f(x) = 1 + 2.1x + 3.0 x^2 + 3x^3
	// double g __gc [] = {1, 2, 2};
	double g [] = { 1, 2, 2 };
	// double h __gc [] = {5};

	double h [] = { 5 };
	
    polynomial *p1 = new polynomial (); 
	polynomial *p2 = new polynomial (f, 2); 
	polynomial *p3 = new polynomial (g, 3);
	polynomial *p4 = new polynomial (h, 1);
	
	polynomial *p7 = new polynomial (p3);
	polynomial *r;
	polynomial *p8 = new polynomial();

	// Console::WriteLine (S"p7 printed as ");

	cout << "p7 printed as " << endl;

	p7->print();
	// Console::WriteLine(S"p1 printed as");

	cout << "p1 printed as" << endl;
    p1->print();
	// Console::WriteLine (S"\np2 is printed as ");
	cout << "\np2 is printed as " << endl;
	p2->print ();
	
	// Console::WriteLine (S"p3 is printed as ");
	cout << "p3 is printed as  \n";
	p3->print ();
/*
	cout << "p8 is \n";
	p8->print();
	p8->add(p2);
	p8->print();
	*/

	// Console::WriteLine(S"p2 * p3 is");
	cout << "p2 * p3 is\n";
	p2->mul(p3);
	p2->print();

	p2->mul(p3);
	p2->print();

//	p2->div(p1, &r);

	double f1 [] = {1, 0, 1, 0, 1};
	double f2 []  = {3, -1, 2};


	polynomial *p5 = new polynomial (f1, 5);
	polynomial *p6 = new polynomial (f2, 3);


	//Console::WriteLine(S"Divisor is ");
	cout << "Divisor is " << endl;
    p6->print ();

	// Console::WriteLine(S"Dividend is ");
	cout << "Dividend is " << endl;
	p2->print();

	r = p2->div(p6);

	
	// Console::WriteLine (S"Quotient is ");
	cout << "Quotient is \n";
	p2->print();

	// Console::WriteLine (S"Remainder is ");
	cout << "Remainder is \n";
	r->print();
	
		
	return 0;
}

/*
old way in 2013
p7 printed as
Polynomial:     1  +    2x  +   2x^2

p1 printed as
Polynomial:     0

p2 is printed as
Polynomial:     1  +    x
p3 is printed as
Polynomial:     1  +    2x  +   2x^2

p2 * p3 is
Polynomial:     1  +    3x  +   4x^2  + 2x^3

Polynomial:     1  +    5x  +   12x^2  +        16x^3  +        12x^4  +
4x^5

Divisor is
Polynomial:     3  +    -x +    2x^2

Dividend is
Polynomial:     1  +    5x  +   12x^2  +        16x^3  +        12x^4  +
4x^5

Quotient is
Polynomial:     -0.25  +        8.5x  + 7x^2  + 2x^3

Remainder is
Polynomial:     1.75  + -20.75x
Press any key to continue . . .

*/
