// File ISBN.cpp: this file computes ISBN 10 and ISBN-13
// ISBN-10: the 10th digits is calculated as d10 = (d1*1 + d2*2 + d3 *3 + … + d8 * 8 + d9 * 9) % 11 .
// ISBN-13: the 13th digit is calculated as d13 =  10 – ((d1 + d3 + d5 + d7 + d9 + d11) – 3* (d2 +d4 +d6 + d8 + d10 + d12)) % 10.
// Examples: ISBN 10: first 9: 013257566 => d10 = 3, 
// ISBN10:

// 013257566 =>   0132575663
// 013605306 => 0136053068
// 160797313 => 1607973138

// ISBN-13

// 978013257566 => 9780132575669
// 978013605306 => 9780136053064
// 978160797313 => 9781607973133

#include <iostream>
using namespace std;
int main () {
	int ISBN10, temp10;
	int IB10[10];
	// Calculate using int type
	cout << "Input the first 9 gits of ISBN-10\n";
	cin >> ISBN10;
	temp10 = ISBN10;
	cout << "First 9 digits input as " << ISBN10;
	// Calculate the 9 digts into an array

	for (int i = 8; i >= 0; i --)
	{
		IB10[i] = temp10%10;
		temp10 /= 10;
	}
	// ISBN-10: the 10th digits is calculated as d10 = (d1*1 + d2*2 + d3 *3 + … + d8 * 8 +d9*9) % 11 .
	// Use IB[i-1] as di for 1 <= i <= 10
	IB10[9] = 0;

	for (int i = 8; i >= 0; i --)
	{
		IB10[9] += IB10[i]*(i+1);
		IB10[9] %= 11;
	}

	cout << "\nCalculated 10th digit of " << ISBN10 << " is " << IB10[9] << endl;

	// Calculate ISBN13
	long long ISBN13, temp13;
	int IB13[13];
	// Calculate using int type
	cout << "Input the first 12 digits of ISBN-13\n";
	cin >> ISBN13;
	temp13 = ISBN13;
	cout << "First 12 digits input as " << ISBN13;
	// Calculate the 12 digts into an array

	for (int i = 11; i >= 0; i --)
	{
		IB13[i] = temp13%10;
		temp13 /= 10;
	}
	// ISBN-13: the 13th digit is calculated as d13 =  10 – ((d1 + d3 + d5 + d7 + d9 + d11) – 3* (d2 +d4 +d6 + d8 + d10 + d12)) % 10
	// Use IB[i-1] as di for 1 <= i <= 10
	IB13[12] = 10;

	for (int i = 11; i >= 1; i -= 2)
		IB13[12] -= IB13[i]*3;
	
	for (int i = 10; i >= 0; i -= 2)
		IB13[12] -= IB13 [i];

	IB13[12] %= 10;
	if (IB13[12] <0)
		IB13[12] += 10;
	cout << "\nCalculated 13th digit of " << ISBN13 << " is " << IB13[12] << endl;
	return 0;

}