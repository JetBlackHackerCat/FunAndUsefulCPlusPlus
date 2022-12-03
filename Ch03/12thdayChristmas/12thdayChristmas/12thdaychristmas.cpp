// 12thday.cpp
// Code to implement printing out of the twelfth day of Christmas
// This one uses switch and case
#include <iostream>
#include <string>
using namespace std;
int main () {
	int n;
	string s1  = "On the ";
	string s2 = " day of Christmas, my true love sent to me ";
	string s;
	string days[4] = {"", "first", "second", "third"};
	string x[4] = {"", "A partridge in a pear tree. ", "Two turtle doves, ", "Three French hens, "};

for (int i = 1; i <= 3; i ++)
{
	// For each i, print the ith day
	s += s1 + days[i] + s2;
	for (int j = i; j >= 1; j --)
		s += x[j];

}
cout << s  << endl;


}
