#include <iostream>
#include "complex.h"
// #define PI 3.14159
using namespace std;
double PI = 4.0 * atan (1.0);
complex::complex (double r, double i) {
	rP = r;
	iP = i;
}

void complex::add (complex  c1, complex  c2) {
	rP = c1.rP + c2.rP;
	iP = c1.iP + c2.iP;
}

void complex::wrongmul ( complex  c1, complex  c2) {
	
	rP = c1.rP * c2.rP - c1.iP * c2.iP;
	iP = c1.rP * c2.iP + c1.iP * c2.rP;
}


void complex::print (){

	cout << rP << "+" << iP << "j" << endl;
	// Console::Write (S" {0} +  {1} j",
	//	rP.ToString (),iP.ToString ());
}

void complex::polar () {
	
	rad = sqrt (rP * rP + iP * iP);
	angle = atan2 (rP, iP);
	angle *= 180.0 / PI;

//	Console::Write (S" polar form r = {0}, angle = {1}\n",
	//	rad.ToString (), angle.ToString());
	cout << "polar form r = " << rad << " angle = " << angle << endl;
		
}

void complex::power (double p) {
	double mulrad, mulangle;
	this->polar();
	mulrad = pow(rad, p);
	mulangle = angle * p; // mulangle in radian
//	mulangle *= 180.0 /  Math::PI;
	while (mulangle >= 360)
		mulangle -= 360;
	while (mulangle < 0)
		mulangle += 360;

rP = mulrad * cos (mulangle * PI / 180.0);
iP = mulrad * sin (mulangle * PI / 180.0);
}
