// This is the main project file for VC++ application project 
// generated using an Application Wizard.

// This file handles huge int class

// #include "stdafx.h"
#include "hugeint.h"
#include <iostream>
using namespace std;

// #using <mscorlib.dll>

// using namespace System;

HugeInt::HugeInt (long value) { // create by a long value 
	// find the number of digits
	int count = 0;  // zero considered one digit. Sign does not matter
	long copy = value;

	while(copy != 0) 
	{
		copy /= 10;
		count ++;
	}
	if (count == 0)
		count = 1;
	size = count;
	// int *z2{ new int[n] {} }; // syntax to declare and initialize
	// int array of size n. With n a variable, this is dynamic
	// int f __gc []; code in 2013
	// f = new int __gc [size]; // code in 2013
	int *f{ new int [size] {} }; 
	// code in 2022: declare and initialize an int array of size to all 0's

	digits = f;
	sign = 1;

	for (int i = 0; value != 0 && i < size; i ++) {
		digits [i] = value % 10;
		value /= 10;
		if (digits [i] < 0) // if any digits is negative
			sign = -1;
	}

}


void HugeInt::copy (HugeInt *h) {
	size = h->size;
	// int g __gc []= new int __gc [size];
	int *g{ new int [size] {} };

	for (int i = 0; i < size; i ++) 
		g[i] = h->digits[i];

	digits = g;
	sign = h->sign;
}

void HugeInt::flip (HugeInt *h) {
	bool nonzero = false;
	// int g __gc [] = new int __gc [h->size];
	int *g { new int [h->size] {} };
	size = h->size;

	for (int i = 0; i < size; i ++)
	{
		g[i] = - h->digits[i];
		if (g[i]!= 0)
			nonzero = true;
	}

	if (nonzero)
		sign = - h->sign;
	else
		sign = 1;

	size = h->size;
	digits = g;


}
void HugeInt::add (HugeInt *a, HugeInt * b) {

	int carry = 0;

// The logic is different depending on the signs of a and b.

	//size = Math::Max(a->size, b->size);
	size = std::fmax(a->size, b->size);
	// int minsize = Math::Min(a->size,b->size);
	int minsize = std::fmin(a->size, b->size);
	// int f __gc []= new int __gc [size];
	int *f{ new int [size] {} };
	bool overflow = false;
	// int c __gc []= new int __gc [size];
	int *c{ new int [size] {} };
	// int d __gc [] = new int __gc [size]; // make copies of a and b
	int *d{ new int [size] {} };
	for (int i = 0; i < minsize; i ++) {
		c[i] = a->digits[i];
		d[i] = b->digits[i];
		f [i] = 0;
	}

	for (int i = minsize; i < size; i ++) {
		if (a->size < b->size)
		{
			c[i] = 0;
			d[i] = b->digits[i];
			f[i] = 0;
		}
		else // a->size > b->size
		{
			c[i] = a->digits[i];
			d[i] = 0;
			f[i] = 0;
		}
	}

	digits = f;

	if (a->sign > 0 && b->sign > 0) { // addition for two positive huge integer


		for (int i = 0; i < size; i ++) {
			digits [i] = c [i] + d [i] + carry;
			carry = 0;

			if (digits [i] >= 10) {
				digits[i] %= 10;
				carry = 1;
				if (i == size - 1)
				{
					overflow = true;
					// Console::WriteLine (S"Add + + overflow");
					std::cout << "Add + + overflow" << endl;
					// allocate one more digit for current huge integer
				//	int g __gc [] = new int __gc [size + 1];
					int *g{ new int[size+1] {} };

					for (int i = 0; i < size; i ++)
						g[i] = digits [i];

					g[size] = 1;

					digits = g;  // increment size and allocate more digits
				}
			}  // end of if (digits[i] >= 10
		} // end of for
        if (overflow)
			size ++;

		
	}  // end of if ( a >= 0 & b > = 0)
	else if (a->sign < 0 && b->sign < 0) {
		for (int i = 0; i < size; i ++) {
			digits [i] = c [i] + d [i] + carry;
			carry = 0;
			if (digits [i] <= -10) {
				digits[i] %= 10;
				carry = -1;
				if (i == size - 1) // overflow
				{
					overflow = true;
					// Console::WriteLine (S"Add - - overflow");
					cout << "Add - - overflow" << endl;
					// int g __gc [] = new int __gc [size + 1];
					int *g{ new int[size+1] {} };
					for (int i = 0; i < size; i ++)
						g[i] = digits [i];

					g[size] = -1;
					digits = g;

					
				}
			}  // end if (digits [i] <= -10
		} // end for loop
		if (overflow)
		
			size ++;
	}  // end of a < 0 & b < 0

	else if (a->sign > 0 && b->sign < 0) {

		// a->add(b) or a + b is equal to a - (-b) or a->sub(-b)
		HugeInt *c = new HugeInt (0);

		c->flip(b); // c = -b
		this->sub(a, c);


	}  // end of a >= 0 & b < 0
	else // a < 0 & b >= 0
	{
		// a + b = b - (-a)
		HugeInt *c = new HugeInt (0);

		c->flip (a); // c = -a

		this->sub(b, c);
	}

	this->check(); // check to make sure size fits
}

void HugeInt::sub (HugeInt *a, HugeInt * b) {

	// we need to consider 4 cases depending on the signs of a and b
	// if a > 0 and b > 0, a - b can be positive or negative depending on if
	// a > b (i.e a->compare(b) > )
	// if a > 0 b < 0, then a - b is actually a + (-b) the sum of two positive
	int borrow = 0;
	// Make copies of a and b of bigger size 
	// size = Math::Max(a->size, b->size);
	size = fmax(a->size, b->size);
	// int minsize = Math::Min(a->size,b->size);
	int minsize = fmin(a->size, b->size);

	// int f __gc []= new int __gc [size];
	int *f{ new int[size] {} };
	
	// bool overflow = false;
	// int c __gc []= new int __gc [size];
	int *c{ new int[size] {} };
	// int d __gc [] = new int __gc [size]; // make copies of a and b
	int *d{ new int[size] {} };
	for (int i = 0; i < minsize; i ++) {
		c[i] = a->digits[i];
		d[i] = b->digits[i];
		f [i] = 0;
	}

	for (int i = minsize; i < size; i ++) {
			if (a->size < b->size)
			{
				c[i] = 0;
				d[i] = b->digits[i];
				f[i] = 0;
			}
			else // a->size > b->size
			{
				c[i] = a->digits[i];
				d[i] = 0;
				f[i] = 0;
			}
		}

	if (a->sign > 0 && b ->sign > 0) {  // compute the difference of two positive hugeint
		if (a->compare(b) > 0) {  // a > b
			for (int i = 0; i < size; i ++) {
				f [i] = c [i] - d [i] - borrow;
				borrow = 0;
				if (f [i] < 0) {
					if (i < size)  // borrow one from digits [i+1]
					{
						borrow = 1; // borrow one from higher digit
						f[i] += 10;
					}
					else
						// Console::WriteLine (S"Subtract too much");
					    cout << "Subtract too much" << endl;
				}  // end of if digits [i] < 0
		
			}  // end of for i < size

	//		digits = f;

			// eliminate starting zeroes

			int j = size -1;
			if (f[size-1] == 0)
				while (f[j] == 0 && j > 0)
					j --;

			size = j + 1;

		//	int g __gc[] = new int __gc [size];
			int *g{ new int[size]{} };

			for (int i = 0; i < size; i ++)
				g[i] = f[i];

			digits = g;

		}  // end of a > b
		else if (a->compare(b) == 0) // a = b
		{
			HugeInt *c = new HugeInt (0);
			this->copy (c);

		}
		else {  // a < b
			// Compute b - a; then add minus signs
			for (int i = 0; i < size; i ++) {
				digits [i] = d [i] - c [i] - borrow;
				borrow = 0;
				if (digits [i] < 0) {
					if (i < size)  // borrow one from digits [i-1]
					{
						borrow = 1; // borrow one from higher digit
						digits[i] += 10;
					}
					else
						// Console::WriteLine (S"Subtract too much");
						cout << "Subtract too much" << endl;
				}  // end of if digits [i] < 0
		
			}  // end of a < b

			for (int i = size - 1; i >= 0; i --)
				digits[i] *= -1;

			sign *= -1;

		}  // else a < b
	}  // end of if (a > 0 && b > 0)
	else if (a->sign < 0 && b->sign < 0) {
		// get c = -a and -b

		HugeInt *c = new HugeInt (0);
		HugeInt *d = new HugeInt (0);

		c->flip(a);
		d->flip(b);
		
		// a - b = d - c (since d = -b, c = -a)
		if (d->compare(c) > 0) {  // d > c
			for (int i = 0; i < size; i ++) {
				digits [i] = d->digits [i] - c->digits [i] - borrow;
				borrow = 0;
				if (digits [i] < 0) {
					if (i > 0)  // borrow one from digits [i-1]
					{
						borrow = 1; // borrow one from higher digit
						digits[i] += 10;
					}
					else
						// Console::WriteLine (S"Subtract too much");
					    cout << "Subtract too much" << endl;
				}  // end of if digits [i] < 0
		
			}  // end of for
		}
		else if (d->compare(c) == 0) // d = c
		{
			HugeInt *e = new HugeInt (0);
			this->copy (e);

		}
		else {  // d < c
			for (int i = 0; i < size; i ++) {
				digits [i] = c->digits [i] - d->digits [i] - borrow;
				borrow = 0;
				if (digits [i] < 0) {
					if (i > 0)  // borrow one from digits [i-1]
					{
						borrow = 1; // borrow one from higher digit
						digits[i] += 10;
					}
					else
						// Console::WriteLine (S"Subtract too much");
					   cout << "Subtract too much" << endl;
				}  // end of if digits [i] < 0
		
			}  // end of d < c

			// reverse the signs
			for (int i = size - 1; i >= 0; i --)
				digits[i] *= -1;

			sign *= -1;

		}  // else d < c

	}  // end of if (a < 0 && b < 0)
	else if (a->sign > 0 && b->sign < 0)  // a >= 0 & b < 0
	{
		// a - b = a + (-b)

		HugeInt *c = new HugeInt (0);
		
		c->flip(b); // c = -b

		this->add (a, c);
	}
	else // a < 0 && b >= 0
	{
		// a - b = - (b + (-a)); Here -a is positive; compute c = -a
		// Then compute d->add(b,c); Then flip the sign of d.

		HugeInt *c = new HugeInt (0);
		HugeInt *d = new HugeInt (0);

		c->flip(a);  // c = -a

		d->add(b, c);

		this->flip(d);
		
	}

	this->check(); // check to make sure size fits


}

void HugeInt::mul (HugeInt *a, HugeInt * b) {
// Multiply two huge integers. 
// Note that the product of a and b can have a size  s of a->size + b->size or s - 1 (or 1 
// if one of them is zero.
HugeInt *c = new HugeInt (0);

if (a->compare(c) == 0 || b->compare (c) == 0)
	this->copy(c);
else {
	// make first size the sum of two sizes
	int newsize, carry = 0;
	newsize = a->size + b->size;

	// int g __gc [] = new int __gc [newsize];
	int *g{ new int[newsize] {} };
	for (int i = 0; i < newsize; i ++)
		g[i] = 0;

//	int carry2 __gc [] = new int __gc [newsize];
	// int c __gc [] = new int __gc [newsize];  // make c copy of a with preceding zeroes
	int *c{ new int[newsize] {} };
	//int d __gc [] = new int __gc [newsize];
	int *d{ new int[newsize] {} };
	for (int i = 0; i < a->size; i ++)
		c[i] = a->digits[i];

	for (int i = a->size; i < newsize; i ++)
		c[i] = 0;

	for (int i = 0; i < b->size; i ++)
		d[i] = b->digits[i];

	for (int i = b->size; i < newsize; i ++)
		d[i] = 0;

	if (a->sign > 0  && b->sign > 0) { // multiply two positive integers
		for (int i = 0; i < newsize ; i ++)
		{
	//		g[i] = 0;
			for (int k = 0; k <= i; k ++) 
				g[i] += c[k] * d[i-k];  // g[i] may be much bigger than 10
            int p = i;
			while (g[p] >= 10)
			{
				
				g[p+1] += g[p] / 10;
				g[p] %= 10;
				p ++;
			}
		}

		digits = g;
		size = newsize;
	} // end of sign> 0 & m->sign > 0
	else if (a->sign > 0 && b->sign < 0) //b is negative
	{
		HugeInt *c = new HugeInt (0);
		c->flip(b); // c = -b;
		this->mul(a, c);
		this->flip(this);  // reverse my sign
	}
	else if (a->sign < 0 && b->sign > 0) // a is negative
	{
		HugeInt *c = new HugeInt (0);
		c->flip(a);  // c = -a
		this->mul(c, b);
		this->flip(this);
	}
	else // a < 0 && b < 0
	{
		HugeInt *c = new HugeInt (0);
		HugeInt *d = new HugeInt (0);

		c->flip(a); // c = -a;
		d->flip(b); // d = -b;
		this->mul(c, d);

	}  // end else


  }  // end of if one is zero

	this->check (); // adjust to the right size

}  // end of method

void HugeInt::div (HugeInt *a, HugeInt *b, HugeInt *r) {
// a / b = q + r / b, q saved in this

// adjust the size of divisor and dividend
	a->check();
	b->check();

	if (b->size == 1 && b->digits[0] == 0)
		// Console::WriteLine (S"Divide by zero error");
	cout << "Divide by zero error" << endl;
	else {
		// if divisor bigger than dividend (in absolute value), 
		// quotient is 0 and remainder = this
		if (a->sign > 0 && b->sign > 0) {
			if (a->compare (b) < 0)
			{
				HugeInt *e = new HugeInt (0);
				r->copy (a);     // remainder = a
				this->copy (e);  // quotient = 0
			}
			else
			{
				// Get the first d->size digits of this (dividend) and call that k
				// If k >= d, then we will divide d by k and get the first digit of
				// quotient and starting digits of remainder

				// if k < d, we need to get one more digit

				HugeInt *e = new HugeInt (0);
				HugeInt *g = new HugeInt (10);
				HugeInt *q = new HugeInt (0);

				q->copy (this);

				bool adddigit = false;

				for (int i = a->size - 1; i >= a->size - b->size; i --)
				{
					HugeInt *f = new HugeInt (a->digits[i]);
					e->mul(e, g); // use Horne's algorithm to compute
					e->add(e, f);
					
				}

				q->size = a->size - b->size + 1;

				// the number of digits of quotients depends on the dividend and the
				// divisor and also depends on the relative size of both

				// Below we assume both dividend and divisor are positive.

				// If dividend < divisor, then quotient = 0.

				// Now assume dividen >=  divisor 
				// if divisor is of m digits and the first m digits of dividend is bigger
				// or equal to the divisor, then number of quotient digits is equal to 
				// dividend digits - divisor digits + 1

				// Example : 252 / 11 = 22 + 10, # of digits in 22 is 2 = 3 - 2 + 1

				// If the fist m digits of dividend is smaller than divisor
				if (e->compare (b) < 0)  // smaller than divisor, add one digit
				{
					HugeInt *h = new HugeInt (a->digits[a->size-b->size -1]);
					e->mul(e, g);
					e->add(e, h);
					adddigit = true;
					q->size -= 1;  // deduct number of digits by 1
				}

				// int qarr __gc []= new int __gc [q->size];
				int *qarr{ new int[q->size] {} };

				q->digits = qarr;


				bool firstfound = false, biggestfound = false;

	//			HugeInt *f = new HugeInt (i1);
	//			HugeInt *f1 = new HugeInt (0);
				HugeInt *f2 = new HugeInt (0);
				HugeInt *f3 = new HugeInt (0);
				int i2;
				// find the largest multiple nb of b that is <= e (so nb <= e, (n+1)b > e).
				for (int i1 = 1; i1 <= 10; i1 ++)
				{
					HugeInt *f = new HugeInt (i1);
					HugeInt *f1 = new HugeInt (0);
	//				HugeInt *f2 = new HugeInt (0);
					f1->mul(b, f);
					if (e->compare(f1) < 0  && e->compare(f2)>= 0)
					{
						biggestfound = true;
						f3->copy(f2);
						i2 = i1 -1;
						break;
						// can compute quotient and remainder now
					}

					f2->copy(f1);
				}
		//		if (biggestfound)
		//			Console::WriteLine (S"biggest multiple is found");

		//		f2->print();

				e->sub(e, f3);

				// e should be less than b now

				HugeInt *f = new HugeInt (i2);
	//			HugeInt *g = new HugeInt (10);
				if (q->size == 1)
				{
					r->copy(e); // remainder = e;
					
					this->copy (f);  // i2 is the quotient

				}
				else // quotient size >= 1
				{
					int i = q->size - 1;
					q->digits[i] = i2;  // set the first quotient digit

					int j;
		
					e->mul (e, g);

					if (adddigit) // moved one digit earlier
					{
						adddigit = false;
						// get next digit
						j = a->size - 1 - b->size - 1;
						HugeInt * g1 = new HugeInt (a->digits[j]);
						e->add (e, g1);

					}
					else
					{
						j = a->size - 1 - b->size;
						HugeInt * g1 = new HugeInt (a->digits[j]);
						e->add (e, g1);

					}
					while (i >= 0  && j >= 0) // will decrement i by 1 normally
						// but may decrement more as needed
					{
						// add the next digit(s) appropriate for division
						/*
						e->mul (e, g);

						HugeInt * g1 = new HugeInt (a->digits[j]);
						e->add (e, g1);
						*/

						// e can be less than b

						if (e->compare(b) < 0) // add enough number of 0s 
						{
							while (i >= 0 && j >= 1 && e->compare(b) < 0)
							{
								i --;
								j --;
								HugeInt *k = new HugeInt (a->digits[j]);
								q->digits[i] = 0;
								e->mul(e, g);
								e->add(e, k);
								
								
							}
						}
						
						i --; 
						j --;
						
						if (i < 0)
							break;
						// Now e is >= b Find multiple of b big enough to be subtracted
						HugeInt *f6 = new HugeInt (0);
						HugeInt *f7 = new HugeInt (0);
						int m2;

						for (int m1 = 1; m1 <= 10; m1 ++)
						{
							
							HugeInt *f4 = new HugeInt (m1);
							HugeInt *f5 = new HugeInt (0);
							f5->mul (b, f4);  // f5 is multiple of b
							if (e->compare(f5) < 0 && e->compare (f6) >=0)
							{
								// found
								f7->copy(f6);
								q->digits[i] = m1 - 1;
								break;
							}
							f6->copy(f5);

						}

						e->sub(e, f7);
						// next digit calculation
						if (j >=0) // when there are digits remaining to calculate
						{
							e->mul (e, g);

							HugeInt * g1 = new HugeInt (a->digits[j]);
							e->add (e, g1);
							}
						
					//	i --;

					}  // end of while loop to calculate quotient

					r->copy(e);
					this->copy(q);

				} // end of quotient size > 1

		
			}
		}  // both > 0
		else if (a->sign > 0 && b->sign < 0)
		{
			HugeInt *c = new HugeInt (0);
			HugeInt *nr = new HugeInt (0);
			// Note when a / -b = q with rem -r, then a / b = -q with rem r
			c->flip (b); // c = - b
			this->div(a, c, nr);
			r->flip (nr);  // r = - nr
			this->flip(this); // reverse the sign of this

		}
		else if (a->sign < 0 && b->sign > 0) 
		{
			HugeInt *c = new HugeInt (0);
			HugeInt *nr = new HugeInt (0);
			// Note when -a / b = q with rem -r, then a / b = -q with rem r
			c->flip (a); // c = - a
			this->div(c, b, nr);
			r->flip (nr);  // r = - nr
			this->flip(this); // reverse the sign of this
		}
		else // both < 0
		{
			HugeInt *c = new HugeInt (0);
			HugeInt *d = new HugeInt (0);
			// Note when -a / -b = q with rem r, then a / b = q with rem r
			c->flip (a); // c = - a
			d->flip (b);
			this->div(c, d, r);
						
		}

	} // end of nonzero divisor
}  // end of div method
void HugeInt::power (HugeInt *a, int b) {
	if (b < 0)
		// Console::WriteLine (S"negative power");
		cout << "negative power" << endl;

	HugeInt *c = new HugeInt (1);
	HugeInt *d = new HugeInt (1);

	d->mul (a, c);
	for (int i = 0; i < b - 1; i ++)
		d->mul(a, d);

	this->copy(d);

}

int HugeInt::compare (HugeInt *b) {
// compare the magnitude of the two huge integers a and b
// return -1 if a < b, 0 if a = b, and 1 if a > b.

// This is useful when doing add and sub of two huge integers one or both may be negative

// If adding and both are positive or both are negative (there is possibility one is zero)
	int retvalue = 0;

	// Make copies with more digits if necessary

	// int maxsize = Math::Max (size, b->size);
	int maxsize = fmax(size, b->size);
	// int minsize = Math::Min (size, b->size);
	int minsize = fmin(size, b->size);

	// int c __gc [] = new int __gc [maxsize];
	int *c{ new int[maxsize] {} };
	// int d __gc [] = new int __gc [maxsize];
	int *d{ new int[maxsize] {} };

	for (int i = 0; i < minsize; i ++)
	{
		c[i] = digits[i];
		d[i] = b->digits[i];
	}

	for (int i = minsize; i < maxsize; i ++)
	{
		if (size < b->size)
		{
			c[i] = 0;
			d[i] = b->digits[i];
		}
		else // siez > b->size
		{
			c[i] = digits[i];
			d[i] = 0;
		}
	}

	
	for (int i = maxsize - 1; i >= 0; i --)
	{
		if (c[i] > d[i])
		{
			retvalue = 1;
			break;
		}
		else if (c[i] < d[i])
		{
			retvalue = -1;
			break;
		}
	}

	return retvalue;
}

void HugeInt::check () {
	// check if the highest digit with index size is zero
	// if so, adjust downward (and dec size) till the the first nonzero term
	// Note if highest term is 0, then size is kept at 1.
	int i = size - 1;
	if (digits[size-1] == 0 && size > 1)
		while (digits[i] == 0 && i > 0)
			i --;
	int j = i + 1;
//	if (size - 1 > i)
//		Console::WriteLine (S"Size adjusted from {0} to {1}", size.ToString(), j.ToString());
	
	// int g __gc [] = new int __gc [i+1];
	int *g{ new int[i+1] {} };

	for (int k = 0; k <= i; k ++)  // make a smaller version
		g [k] = digits [k];

	digits = g;
	
	
	size = i + 1;

    


		
}


void HugeInt::print () {
	// skip leading zeroes
	int j = size - 1;
	if (digits [j] == 0)
		while (j >= 0 && digits[j] == 0)
			j --;
	if (j >= 0)
		// Console::Write(digits[j]);
		cout << digits[j]; 
	else
		// Console::Write(0);
	    cout << 0; 
	for (int i = j - 1; i >= 0; i --)
		// Console::Write (Math::Abs(digits[i])); 
	    cout << abs(digits[i]); 
}

