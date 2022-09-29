/***************************************************************
* Project Goals:
*
*	An application that lets the user roll for a dice equation
* 
*	The roll can either have advantage(roll twice choose 
*	higher roll), disadvantage(roll twice choose the lower roll),
*	or none(roll once)
* 
*	The equation is as follows:
* 
*	N*D+M such that N = number of rolls, D = type of dice, and M = modifier
*
*	Bonus Objective/Stretch Goal:
*		Add a menu option to choose to either simply roll dice
*		or to roll to beat a set number or roll to beat another
*       roll. Then implement those as functions
****************************************************************/

#include "DiceRoller.h"
#include <string>

int main()
{
	std::string userInput = "";

	do
	{
		system("cls");
		for (int i = 0; i < 25; i++)
		{
			std::cout << DiceRoller::GetRandomNum(1, 20) << "\n";
		}

		std::cout << "\n\n\nq to quit: ";
		DiceRoller::ClearCin();
		std::getline(std::cin, userInput);

	} while (userInput != "quit" && userInput != "q");

	return 0;
}