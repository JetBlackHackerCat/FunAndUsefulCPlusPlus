#include <iostream>
using namespace std;
int  main() {				
//		 File mortgage.cpp
//		 This file computes the mortgage montly payment given
//		 the principal P, the period n years, the MONTLY rate r
//		 Author: Dr. Tim Lin
//		 Date: 3/21/06

//		 The formula that P and its compound interest over n years is
//		 A1 = P * (1 + r)^12n (there are 12 n months)
		//
//		 with monthly installment I, the accumulated repayment plus interest is
//		 A2 = I * [ (1+r)^ (12n - 1) + (1 + r) ^ (12n - 2)+ (1+r) ^ (12n -3) +...
//		       + (1+r)^2 + (1+r) + 1] = I * [ (1+r) ^ 12n - 1] / r
//		 A1 must be equal to A2. Hence, given P, r, and n, we can compute
//		 I
		   double P, r, I, x; // principal, monthly rate, and installment
		   int n; // number of years
           cout << "Input principal and annual rate in %\n";
           cin >> P >> r;	   
		   r = r /1200;   
	  	   cout << "Input number of years\n";		
		   cin >> n;
		   cout << "Compute (1+r)^ 12n\n";
		   x = pow (1+r, 12 * n);
		   cout << "pow (1+r, 12*n) AKA x is " << x << endl;
		     I = P * x * r / (x -1);

		   cout << "installment is " << I << endl;
		   cout << "Total payment is " << 12 * n * I << endl;		      		   
		   // Compute remaining term using rate r, printicpal P, adn installment I.
		     // From balance.doc, we find x = 1 / (1 – Pr / I)  
		   // Hence 12n = log x with base (1+rO or ln(x) / ln (1+r).
		   double installment;
		   cout <<  ("Input monthly installment: ");
		   // installment = input.nextDouble(); Old Java code
		   cin >> installment;
		   double newx = 1.0 / ( 1 - P* r / installment);		   
		   int months = 0;		   
		   // months = (int) ((Math.log(newx)) / Math.log(1 + r));	 // code for Java	   
           months = (int) ((log(newx)) / log(1 + r)) + 1;	// code for C++
		   cout << "Remaining number of months is " <<  months << endl;
		   
	}
