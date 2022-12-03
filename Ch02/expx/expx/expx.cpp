#include <iostream>
using namespace std;
#define MAX 1.0e308
int  main() {
	// This method computes the exponential of a value x input from
	// the text box		
	double x, term = 1.0, sum = 1.0; // Input
//	String xString;		
//	double epsilon = 1.0e-7;
	double epsilon = 1e-7;
	//	xString = JOptionPane.showInputDialog("Enter a number\n");
	//	x = Double.parseDouble(xString);
	cout << "Enter a number\n";
	cin >> x;
	for (int i = 1; abs(term) > epsilon; i++)
		//	for (int i = 1; i < 5; i ++)
	{
		term *= x / (double)i;
		if (term > MAX)
		{
			cout << "Overflow for term happens at i = " << i << endl;
			break;
		}
		sum += term;
		if (sum > MAX)
		{
			cout << "Overflow for sum happens at i = " << i << endl;
			// break;
		}
		//		cout << "For step " <<  i <<  "  Sum is " << sum << endl;

	}
	cout << "exp (" << x << ") = " << sum << endl;
	cout << "Exp (x) from Math library is " << exp(x) << endl;

	cout << "Difference is " << sum - exp(x) << endl;
}
