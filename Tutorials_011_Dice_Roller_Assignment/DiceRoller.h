#ifndef DICE_ROLLER_H
#define DICE_ROLLER_H
#include <iostream>

namespace DiceRoller {
	/*Function clears cin of any errors it may have then ignores the current
	available buffer to ensure next input is fresh*/
	void ClearCin();

	//single instance variable that will let the program know if we have
	//seeded random function yet
	static bool RAND_SEEDED = false;

	int GetRandomNum(int min, int max);
}

#endif // !DICE_ROLLER_H
