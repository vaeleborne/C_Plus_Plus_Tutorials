#include <iostream>

/***************************************************************
* Project Goals:
*
*	Introduce the most common types of variables and show
*	examples of how to use them
* 
****************************************************************/

int main()
{
	// NUMBERS

	//int = integer. Is 32bit so range of possible values is (-2^31) - 1 through (2^31) - 1, it's 31 not 32 because one bit is used to 
	//	determine if the number is positive or negative
	int integerOne = 1;
	int integerTwo(2);
	int integerThree;
	int integerFour;
	
	integerThree = -3;
	integerFour = integerTwo + integerOne + integerOne;

	int maxSigned = 2147483647;
	unsigned int maxUnsigned = 4294967295;

	//DECIMALS

	//Float is 32bit
	float floatingPointNumber = 12.3456;

	//Double is 64 bit
	double doubleNumber = 12.3456;

	//NON NUMBERS
	char characterOne = 'a';
	char characterTwo = '1';

	bool isTrue = true;
	bool isFalse(false);

	std::string stringOne = "This is a string!";
	std::string stringTwo = "Here is another.\nHere is yet another!";

	std::cout << integerOne << " " << integerTwo << " " << integerThree << " " << integerFour << "\nMax Signed Integer: " << maxSigned
		<< "\nMax Unsigned Integer: " << maxUnsigned << "\n" << floatingPointNumber;

	std::cout << " " << doubleNumber << " " << characterOne << " " << characterTwo << '\n' << stringOne << " " << stringTwo << "\n"
		<< "isTrue is: " << isTrue << " which means it is TRUE!\nisFalse holds the value of: " << isFalse;

	return 0; 
}