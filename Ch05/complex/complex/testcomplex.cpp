
#include <iostream>
#include "complex.h"
using namespace std;
int main () {
	complex c1 (2,3);
	complex c2 (4,5);
	complex c3  (0,0);
	complex c4  (1, 1);
	complex c5 (1, -1);
	/*
	c4->polar();
	c4->power(2.0);
	c4->print();
	*/
	c3.wrongmul (c4, c5);
	cout << "print wrong product c3\n";
	c3.print();
	c4.wrongmul (c4,c5);
	cout << "print wrong product c4\n";
	c4.print ();

	c3.polar();

	c3.add (c1, c2);
//	Console::Write (S"The sum of ");
	c1.print ();
//	Console::Write (S" and ");
	c2.print ();
//	Console::Write (S" is ");
	c3.print ();
//	Console::WriteLine (S" ");
	return 0;
}

