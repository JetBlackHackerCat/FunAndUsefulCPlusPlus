#include <iostream>
using namespace std;
int main () {
	double x [] = {2,	4,	3,	4,	6,	4,	4,	1,	5,	4,	3,	4,	5,	4,	10,	4,	1,	1,	4,	4,	4,	4,	5,	4,	
		             10, 7,	4,	2,	5,	4,	4,	6,	4,	5};
	int s = sizeof (x) / sizeof (double);
	cout << "Size of avg array is " << s << endl;
	// Compute the average of the avg array";
	double sum = 0.0;
	double average;
	for (int i = 0; i < s; i ++)
		sum += x[i];

	average = sum/s;
	cout << "Average of avg array is " << average << endl;

	// Compute sample variance and standard deviation
	// Compute sum of (x[i] - average)^2
	
	double var, std; // unbiased variance and standard deviation

	sum = 0.0;
	for (int i = 0; i < s; i ++)
		sum += (average - x[i]) * (average - x[i]);

	var = sum / (s-1);
	std = sqrt (var);
	cout << "Standard deviation is  " << std << endl;
	return 0;
}
/*
Size of avg array is 34
Average of avg array is 4.26471
Standard deviation is  1.97421
*/
