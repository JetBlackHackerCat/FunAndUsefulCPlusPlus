// #include "stdafx.h" // code in 2013
// #using <mscorlib.dll>
// using namespace System;
// public __gc  class HugeInt { // code in 2013

class HugeInt {

public:

//	HugeInt (HugeInt *); // copy constructor 
	                     
	HugeInt (long); // constructor by type long

	void add (HugeInt *, HugeInt *);
	void sub (HugeInt *, HugeInt *);
	void mul (HugeInt *, HugeInt *);
	void check (); // check if highest term is 0 and adjust accordingly
	void power (HugeInt *, int);  // power of a huge integer with int power
    void div (HugeInt *, HugeInt *, HugeInt *);
	void copy (HugeInt *); // copy a huge int
    int compare (HugeInt *);  // compare the two huge integers
    void flip (HugeInt *); // filp the sign of the huge int unless that is zero
	void print (); // display the huge integer

private:

	int size;
	// int digits __gc [] ;  // huge integer of 40 digits
	int *digits = new int[size];

	int sign; // sign of huge integer, 1 for positive or zero, -1 for negative

};