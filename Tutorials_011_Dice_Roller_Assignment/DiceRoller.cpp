#include "DiceRoller.h"

void DiceRoller::ClearCin()
{
	//Clears cin of any error codes
	std::cin.clear();

	//If anything is in the cin buffer this will ignore it
	std::cin.ignore(std::cin.rdbuf()->in_avail());		
}

int DiceRoller::GetRandomNum(int min, int max)
{
	int rtn = 0;

	//Check if seeded first as most calls will happen after it is
	if (RAND_SEEDED)
	{
		rtn = std::rand() % (max - min + 1) + min;
	}
	else
	{
		//If not seeded then we seed it
		std::srand(time(NULL));
		RAND_SEEDED = true;
		rtn = std::rand() % (max - min + 1) + min;
	}

	return rtn;
}

