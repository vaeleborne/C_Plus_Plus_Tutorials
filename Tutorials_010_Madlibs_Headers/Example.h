#ifndef EXAMPLE_H
#define EXAMPLE_H
#include <iostream>
#include <sstream>

/*A function to get a random integer number within
a range given a minimum value and a maximum value*/
int RandomNumberInRange(int min, int max);

namespace MadQuests
{
	/*Function that will initialize the program with word banks to choose from, we pass
	in arrays which contain multiple of a variable type, arrays are passed by reference
	so when we make a change in the function to it it changes it outside of the function as well*/
	void InitializeArrays(std::string race[6], std::string title[6], std::string action[6],
		std::string noun[6], std::string adjective[6], std::string condition[6]);

	/*Will generate a quest based on word banks and random numbers*/
	std::string GetQuest(std::string race[6], std::string title[6], std::string action[6],
		std::string noun[6], std::string adjective[6], std::string condition[6]);

	//Will write a passed integer as it's english name
	std::string numToWord(int num);

	//Here we make a word uppercase, since we want to actually change the variable passed we pass it by reference by adding the &
	void MakeUpperCase(std::string& word);

}

#endif // !EXAMPLE_H

