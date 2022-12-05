// #include "stdafx.h"
#include "hugeint.h"
// #using <mscorlib.dll>
#include <iostream>
// using namespace System;
using namespace std;

// int _tmain()
int main()
{

	// Note possible test cases (that had helped found code bugs are:
	// g = 234, h = 23
	// g = 23, h = 23 (found the bug q = 0, r = 23)
	// g = 230, h = 23 (found the bug when there are 0s left)
	// g = 21745, h = 23 (found when first two digits of g < h)
	// g = 27745, h = 23 (found when first two digits of g > h)

	HugeInt *h = new HugeInt(234);
	HugeInt *g = new HugeInt(234567);
	HugeInt *j = new HugeInt(0);
	HugeInt *k = new HugeInt(0);

	// Console::Write(S"Dividend = ");
	cout << "Dividend = ";
	g->print();
	//Console::Write(S"\nDivisor = ");
	cout << "\nDivisor = ";
	h->print();
	// Console::WriteLine();
	cout << endl;
	j->div(g, h, k);
	// Console::Write(S"\nQuotient is ");
	cout << "\nQuotient is ";
	j->print();
	// Console::Write(S"\nRemainder is ");
	cout << "\nRemainder is ";
	k->print();
	// Console::WriteLine();
	cout << endl;

	HugeInt *a = new HugeInt(1);

	j->copy(a);
	for (int i = 1; i <= 50; i++)
	{
		HugeInt *b = new HugeInt(i);
		j->mul(j, b);
		// Console::Write(S"\n{0}! = ", i.ToString());
		cout << i << "! is "; 
		j->print();
		cout << endl;
	}

	// Console::WriteLine();
	cout << endl;
	/*
	Console::Write (S"Sum of ");

	g->print();

	Console::Write (S" and ");

	h->print ();

	Console::Write (S" is ");

	j->add(g,h);

	j->print();

	int m = h->compare (g);

	Console::WriteLine (S"\nh comparing g is {0}", m.ToString());


	Console::WriteLine();

	Console::Write (S"Difference of ");

	g->print();

	Console::Write (S" and ");

	h->print ();

	Console::Write (S" is ");

	j->sub(g, h);

	j->print();

	Console::WriteLine();

	Console::WriteLine (S"Multiply");
	j->mul(g, k);

	j->print();

	Console::WriteLine (S"Multiply huge numbers");

	j->mul(j, j);

	j->print();

	Console::WriteLine ();


	/*
	j->add(g, h);

	j->print();

	Console::WriteLine();
	*/

	return 0;
}
