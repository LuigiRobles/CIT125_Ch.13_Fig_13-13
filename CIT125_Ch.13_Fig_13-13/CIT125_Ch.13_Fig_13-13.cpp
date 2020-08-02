// CIT125 Intro To C++ Luigi Robles
// 08-01-2020 Summer Term
// Ch.13 pg.475 Fig.13-13 Zip Code Program
// Checks whether a ZIP code contains valid number of characters
// and whether each character is a number

#include <iostream>
#include <string>
using namespace std;

//function prototype
char verifyNumeric(string zip);

int main()
{
	//declare and initialize variables
	string zipCode = "";
	char isAllNumbers = ' ';

	cout << "Five-character ZIP code (-1 to end): ";
	cin >> zipCode; //input for ZIP code

	while (zipCode != "-1")
	{
		if (zipCode.length() == 5) //checking ZIP code for 5 characters
		{
			cout << "-->Correct number of characters";
			isAllNumbers = verifyNumeric(zipCode);
			if (isAllNumbers == 'Y')
				cout << endl << "-->All numbers";
			else
				cout << endl << "-->Not all numbers";
			//end if
		}
		else
			cout << "-->Incorrect number of characters"; //False path for anything below 5 characters
		//end if
		cout << endl << endl;

		cout << "Five-characters ZIP code (-1 to end): ";
		cin >> zipCode; //continue with loop if -1 is not entered
	} //end while
	return 0;
} //end of main function

//******Function Definitions*****
char verifyNumeric(string zip)
{
	//determine whether each character is a number
	string currentChar = "";
	int sub = 0; //character subscript
	char isANumber = 'Y'; //assume all numbers

	while (sub < 5 && isANumber == 'Y')
	{
		currentChar = zip.substr(sub, 1);
		if (currentChar >= "0" && currentChar <= "9")
			//character is numeric, so check next character
			sub += 1;
		else
			//character is not a number
			isANumber = 'N';
		//end if
	} //end while
	return isANumber;
} //end of verifyNumeric function