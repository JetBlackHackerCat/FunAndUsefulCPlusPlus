#include <iostream>
short getCardType();
void getCardNumber(char []);
bool checkPrefix(int, char []);
bool checkLuhn(char []);
using namespace std;
void main()
{
	short selection = getCardType();
	char cardNumber[17] = "0";

	getCardNumber(cardNumber);
	if (checkPrefix(selection, cardNumber))
	{
		if (checkLuhn(cardNumber))
		{
			if (selection == 1)
				cout << "Valid MasterCard number.\n";
			else
				cout << "Valid VISA number.\n";
		}
		else
		{
			if (selection == 1)
				cout << "Invalid MasterCard number.\n";
			else
				cout << "Invalid VISA number.\n";
		}
	}
	else
		cout << "Invalid card number.\n";
}

short getCardType()
{
	bool validSelection = false;
	short selection;

	while (!validSelection)
	{
		cout << "Select credit card type:" << endl;
		cout << "1. MasterCard" << endl;
		cout << "2. VISA" << endl;
		cout << "Selection: ";
		cin >> selection;
		if (selection == 1 || selection == 2)
			validSelection = true;
		else
			cout << endl << "INVALID SELECTION!\n" << endl;
	}

	cout << endl;
	if (selection == 1)
		cout << "MasterCard chosen" << endl;
	else
		cout << "VISA chosen" << endl;
	return selection;
}
void getCardNumber(char cardNum[])
{
	cout << "Enter number (16 digits): ";
	cin >> cardNum;

	cout << "\nYou entered: ";
	for (int i=0; i <= 16; i++)
	{
		cout << cardNum[i];
		if ((i % 4 == 3) && (i != 15))
			cout << '-';
	}
	cout << endl;
}
bool checkPrefix(int selection, char cardNum[])
{
	if (selection == 1)  // Validate Master card prefix 51-55
	{
		if ((cardNum[0] == '5') && ((cardNum[1] == '1') ||
			(cardNum[1] == '2') || (cardNum[1] == '3') || 
			(cardNum[1] == '4') || (cardNum[1] == '5')))
		{
			cout << "Valid MasterCard prefix" << endl;
			return true;
		}
		else
		{
			cout << "Invalid MasterCard prefix" << endl;
			return false;
		}
	}
	else  // Validate Visa prefix 4
	{
		if (cardNum[0] == '4')
		{
			cout << "Valid VISA prefix" << endl;
			return true;
		}
		else
		{
			cout << "Invalid VISA prefix" << endl;
			return false;
		}
	}
}

bool checkLuhn(char cardNum[17])
{
	short sum = 0;

	int i;

	for (i=0; i<8; i++)
		sum += (((2*(cardNum[i*2]-48)) / 10) + ((2*(cardNum[i*2]-48)) % 10));
	
	for (i=0; i<8; i++)
		sum += (cardNum[i*2+1]-48);

	if (sum % 10 == 0)
		return true;
	else
		return false;
}

