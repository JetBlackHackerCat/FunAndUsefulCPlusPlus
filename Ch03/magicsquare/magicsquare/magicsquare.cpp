#include <iostream>
#include <conio.h>
using namespace std;

void main()
{
	int **magicSquare = 0;
	int n, k, i, j, next_row, next_column, init_row, init_column;
	k = 2;
	cout <<"Size of magic square? (N = ?)  \n";
	cin >>n; //get size of magic square
	cout <<"\n";

	magicSquare = new int *[n] ;  // Allocate arrays of n pointers to int array
	for(i = 0 ; i < n ; i++)
		magicSquare[i] = new int[n]; // For each row, allocate n entries

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			magicSquare[i][j] = 0;
		}
	} //initialize dynamic array to all "0"

	init_row = 0;
	init_column = n/2;
	
	magicSquare[init_row][init_column] = 1; //sets the top row, center element to 1
	
	for (i = 0; i < (n*n)-1; i++)//for as many moves as it takes to fill the square, run a loop
	{		
		next_row = init_row - 1; //move UP one row
		next_column = init_column + 1; //move RIGHT one column
		if (next_row < 0)
			next_row = n-1; //if next row is above the square, reset to the bottom row
		if (next_column > n-1)
			next_column = 0; //if next column is right of the square, reset to leftmost column
		if (next_row == -1 && next_column == n) //if square goes off of the top-right element, 
							// place k right below it
		{
			next_row = 1;
			next_column = n-1;
		}

		if (magicSquare[next_row][next_column] != 0) //if the next square is occupied, place k below it
		{
		next_row = init_row + 1;
		next_column = init_column;
		}

		magicSquare[next_row][next_column] = k; //once a valid row and column are found, store k there
		init_row = next_row; //initialize for next loop
		init_column = next_column; //initialize for next loop
		k++; //increment k
		
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout <<magicSquare[i][j] <<"\t  "; //print all the elements with good format
		}
		cout <<"\n";
	}
	cout <<"\n";
	cout<<"\nHit any key to exit.\n";
	// getch();
}
