#include "Example.h"

int main()
{
	std::string race[6], title[6], action[6], noun[6], adjective[6], condition[6];
	char playAgain = 'n';

	MadQuests::InitializeArrays(race, title, action, noun, adjective, condition);

	do
	{
		system("cls");

		std::cout << MadQuests::GetQuest(race, title, action, noun, adjective, condition)
			<< "Would you like to get another? (y/n): ";

		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> playAgain;

	} while (playAgain == 'y');

	return 0;
}