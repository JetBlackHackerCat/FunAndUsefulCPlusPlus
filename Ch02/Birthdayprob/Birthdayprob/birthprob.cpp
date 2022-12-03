#include <iostream>
using namespace std;

int main() // line1: main
{   // line 2: left brace to start the main function
    // The formula is 1 - P(365, n)/365^n
    // Note for the formula to be meaningful, n  must be <= 365
	//
	// Prompt for two different types of computation
	int x = 0;
	while (x != 1 && x != 2) {
		cout << "Enter 1 to compute the probability of two same birthdays for 20 people\n";
		cout << "Enter 2 to compute such probabilities from 11 to 50 people\n";
		cin >> x;
	}

	if (x == 1) {
		double bp = 0.0;
		int n = 20;
		double term = 1.0;
		for (int i = 0; i < n; i++)
			term *= (365 - i) / 365.0;
		bp = 1 - term;
		cout << "Probability that in a party of " <<
			n << " people, two get the same birth day is " << bp;
	}

	if (x == 2)
	{
		double bp = 0.0;
		double term = 1.0;
		for (int k = 11, count = 1; k <= 50; k++, count++)
		{
			term = 1.0;
			for (int i = 0; i < k; i++)
				term *= (365 - i) / 365.0;
			cout << 1.0 - term << '\t' << " ";
			if (count % 5 == 0)
				cout << endl; // move to next line for every 5 number

		}
	}

} // line 6: end method main
