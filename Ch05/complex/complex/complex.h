#ifndef COMPLEX_H
#define COMPLEX_H
class complex {
	public:
		complex (double, double);  //constructor
		void add (complex ,  complex );
		void sub (complex ,  complex );
		void mul (complex , complex );
		void wrongmul (complex , complex );
		void div  (complex , complex );
		void polar ();  // converts this to polar form
		void print ();
		void power (double); // raise the complex number to a power
	private:
		double rP; // real part
		double iP; // imaginary part
		double rad; // radius
		double angle ; // argument
};
#endif

