/***************************************************************
* Project Goals:
*
*	Introduce the most common types of variables and show
*	examples of how to use them
*
****************************************************************/

#include <iostream>
#include <string>

int main()
{
	std::string name;
	int age;

	std::cout << "Hello, how old are you in years? : ";

	//Similar to cout to display a message we can use cin to get a value from the user. cin stands for console input
	std::cin >> age;
	std::cout << "\nDid you know that is " << age * 365 << " days?\nOh I never asked, what is your name? : ";

	//We are going to add protection here to clear the input buffer in order to avoid unwanted results, try without to see
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	/********************************************************************************************************************************
		We use getline for string inputs rather than cin.The first argument(std::cin) tells the program where to get the line
		From, in the future we can use this to read from a file. The second argument(name) takes a variable that will be set to the
		Lines value. If this is confusing don't worry, it will come with time and practice. 
	******************************************************************************************************************************/
	std::getline(std::cin, name);
	std::cout << "Hello " << name << "!" << "\n\n\n";

	// Multiplier
	int x;
	int y;

	std::cout << "Enter a value for x: ";
	std::cin >> x;
	std::cout << "\nEnter a value for y: ";
	std::cin >> y;

	std::cout << "Okay " << name << ", " << x << " x " << y << " = " << x * y;

	//Next We will make a basic calculator for two values based on some logic and user input
	return 0;
}