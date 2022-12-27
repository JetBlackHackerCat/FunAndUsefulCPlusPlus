#include <iostream>
using namespace std;
int main() {
    int jd, d, m;
    cout << "Enter month number and day number" << endl;
    cin >> m >> jd;
    int monthdays [13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 31, 30 };
    // number of days in each month
    for (int j = 1; j < m; j += )
        jd += monthdays[j];  // add number of days in the month before month m
    jd += d;   // add the number of days in d.
}

