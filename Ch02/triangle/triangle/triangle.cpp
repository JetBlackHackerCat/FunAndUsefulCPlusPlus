#include <iostream>
using namespace std;

int tri, obt, rgt, acute, iso, equ;
bool checkTriangle(int, int, int); // function prototype

int main()
{
	// TODO: Please replace the sample code below with your own.
	int n = 10;  // find all triangles with int side up to n
//	int tri, obt, rgt, acute, iso, equ;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				checkTriangle(i, j, k);

	// Console::Write(S"For n = {0}, Number of triangles is {1} ", n.ToString(),
	cout << "For n = " << n <<  ", number of triangles is " << tri << endl;

	cout << " Obtuse count: " << obt << " right tri count: " << rgt << " acute triangle count: " << acute;
	cout << "\n Isoceles triangles count: " << iso << " Equilateral count: " << equ;
		
	return 0;
}

bool checkTriangle(int i, int j, int k) {
	bool ret;

	if (i <= 0 || j <= 0 || k <= 0)
	{
		//	Console::WriteLine (S"one side is <= 0,:  {0}, {1}, {2}",
		//		i.ToString(), j.ToString(), k.ToString());
		return false;
	}

	if (i + j <= k || j + k <= i || k + i <= j) {
		//	Console::WriteLine (S"Tri ineq not satisfied,:  {0}, {1}, {2}",
		//		i.ToString(), j.ToString(), k.ToString());
		return false;
	}

	// In the following we check for obtuse, right, or acute triangles

	if (i * i > j * j + k * k || j * j > i * i + k * k || k * k > i *
		i + j * j) {
		// obtuse triangle
	//		Console::WriteLine (S"Obtuse triangles; {0}, {1}, 
	//	{2}",
	//		i.ToString(), j.ToString(), k.ToString());
		obt++;
		tri++;
		ret = true;
	}
	else

		if (i * i == j * j + k * k || j * j == i * i + k * k || k * k
			== i * i + j * j) {
			// rectangle triangle

			rgt++;
			tri++;
			ret = true;
		}
		else

			// acute triangle

		{
			//	Console::WriteLine (S"Acute triangles: {0}, {1}, {2}",
			//		i.ToString(), j.ToString(), k.ToString());
			acute++;
			tri++;
			ret = true;

		}

	// In the following we check for isoceles and equilateral
	if (i == j || i == k || j == k)
	{
		//	Console::WriteLine (S"Isoceles triangles: {0}, {1}, {2}",
		//		i.ToString(), j.ToString(), k.ToString());

		iso++;
	}

	if (i == j && i == k)
	{
		//	Console::WriteLine (S"Equilateral triangles: {0}, {1}, {2}",
		//		i.ToString(), j.ToString(), k.ToString());

		equ++;
	}
	return ret;
}
/*
or n = 10, number of triangles is 505
 Obtuse count: 225 right tri count: 12 acute triangle count: 268
 Isoceles triangles count: 205 Equilateral count: 10
*/
