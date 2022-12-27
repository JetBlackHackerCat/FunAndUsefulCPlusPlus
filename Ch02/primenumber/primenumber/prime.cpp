#include <iostream>
using namespace std;
bool isPrime(int ); // function prototype
void  main() {
		int n = 200;  // Set n = 100 here. n can be input
		int count = 0;
		for (int i = 2; i <= n ; i++)  // 
		{
			if (isPrime(i) == true) // call method to check 
			{
				cout << i  <<  "\t"; // use tab for formatting
				count ++;
				if (count % 8 == 0)  // move to next line every 8 primes
					cout << endl;
			}		
		}
		cout <<  "\nNumber of primes from 2 to "  <<  n  <<  " is "  << count << endl;
}	
	bool isPrime (int k){  // method to check if k is a prime
		for (int j = 2; j <= sqrt((double)k); j ++)  // Need to check up to square root only
			if (k%j == 0)  // if j divides k
				return false;
		
		return true;
		}	
// }

