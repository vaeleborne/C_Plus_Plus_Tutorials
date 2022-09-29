/***************************************************************
* Project Goals:
*
*	Introduce using logic statements
* 
*	We will make a basic calculator that gets two numbers and
*	an operator from the user, then displays the results
* 
*	Bonus Objective/Stretch Goal: Add Further conditions to 
*	check for invalid operations such as dividing by 0
*
****************************************************************/

#include <iostream>
#include <string>

int main()
{
	std::string name;
	float x;
	float y;
	float answer;
	char oper;
	bool invalid = false;

	std::cout << "Welcome To Your Personal Basic Calculator\n\n\nWhat is your name? : ";
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::getline(std::cin, name);

	std::cout << "\n\nOkay " << name << ", lets start with having you enter the first number: ";
	std::cin >> x;
	std::cout << "\nAwesome! Now what would you like to do with it? (+, -, x, /): ";
	std::cin >> oper;
	std::cout << "\nAlright, what is the other number? : ";
	std::cin >> y;

	std::cout << "\n\n\nOkay " << x << oper << y << "=";

	//Lets add logic to get the answer
	if (oper == '+')
	{
		answer = x + y;
	}
	else if (oper == '-')
	{
		answer = x - y;
	}
	// || means or && is and, for && to be true the right and left side of it must be true for or either the left or right side needs to be
	// == checks to see if something is equal to whereas != checks to see if it is NOT Equal to
	else if (oper == 'x' || oper == 'X' || oper == '*' && oper != '/')
	{
		answer = x * y;
	}
	else if (oper == '/')
	{
		//Stretch Goal
		if (y == 0)
		{
			system("cls");
			std::cout << "Cannot divide by 0!!!";
			invalid = true;
		}
		else
		{
			answer = x / y;
		}
	}
	else
	{
		invalid = true;
	}

	if (!invalid)
	{
		std::cout << answer << "\n\n\n";
	}
	else
	{
		system("cls");

		//Stretch Goal
		if (y == 0)
		{
			system("cls");
			std::cout << "Cannot divide by 0!";
		}
		else
		{
			std::cout << "That was not a valid operand!!!";
		}
	}

	//Next Challenge project Rock Paper Scissors

	return 0;
}