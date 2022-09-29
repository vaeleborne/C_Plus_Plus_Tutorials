#include "Example.h"

int RandomNumberInRange(int min, int max)
{
	int randomNum;	//The return variable

	static bool firstRun = true;		//A static variable used to determine if rand() has been seeded

	//Only want to run this next line once, lets use a Static variable
	//Using our static variable we can check if it is set to true(this is the first run of the function), if so we seed rand
	if (firstRun)
	{
		std::srand(std::time(NULL));
		firstRun = false;
	}

	randomNum = min + std::rand() % (max - min + 1);	//Set the return variable equal to a random num between the min and max

	return randomNum;	//Return the return variable now that it has been set
}

void MadQuests::InitializeArrays(std::string race[6], std::string title[6], std::string action[6],
	std::string noun[6], std::string adjective[6], std::string condition[6])
{
	race[0] = "Human";
	race[1] = "Dwarf";
	race[2] = "Elf";
	race[3] = "Undead";
	race[4] = "Goblin";
	race[5] = "Orc";

	title[0] = "matron";
	title[1] = "lord";
	title[2] = "smith";
	title[3] = "baronness";
	title[4] = "knight";
	title[5] = "rogue";

	action[0] = "guard";
	action[1] = "investigate";
	action[2] = "retrieve";
	action[3] = "craft";
	action[4] = "deliver";
	action[5] = "destroy";

	noun[0] = "warlock";
	noun[1] = "ghost";
	noun[2] = "tomb";
	noun[3] = "sword";
	noun[4] = "hermit";
	noun[5] = "fort";

	adjective[0] = "hallowed";
	adjective[1] = "gray";
	adjective[2] = "lost";
	adjective[3] = "fiery";
	adjective[4] = "evil";
	adjective[5] = "honorable";

	condition[0] = "invisibility";
	condition[1] = "unconsciousness";
	condition[2] = "deafening";
	condition[3] = "blindness";
	condition[4] = "poisoning";
	condition[5] = "incapacitation";

	//instead of typing the words in uppercase we made a funtion for practice, lets use it
	for (int i = 0; i < 6; i++)
	{
		MakeUpperCase(race[i]);
		MakeUpperCase(title[i]);
		MakeUpperCase(action[i]);
		MakeUpperCase(noun[i]);
		MakeUpperCase(adjective[i]);
		MakeUpperCase(condition[i]);
	}

}

std::string MadQuests::GetQuest(std::string race[6], std::string title[6], std::string action[6],
	std::string noun[6], std::string adjective[6], std::string condition[6])
{
	std::string rtn;
	std::stringstream stream;

	//We will need 7 total random numbers as we will use 1 extra as just a number
	//to keep things simple we will use an array to hold the numbers and a 
	//combination of a for loop and our randomnumber function to create them
	int randomNumber[7];
	for (int i = 0; i < 7; i++)
	{
		randomNumber[i] = RandomNumberInRange(0, 5);
	}

	//Now that we have our numbers we can fill out the quest

	stream << "A " << race[randomNumber[0]] << " " << title[randomNumber[1]] << " seeks adventurers to "
		<< action[randomNumber[2]] << " a " << noun[randomNumber[3]] << " called the "
		<< adjective[randomNumber[4]] << " " << noun[randomNumber[3]] << " of " << numToWord(randomNumber[4] + 1)
		<< " " << condition[randomNumber[5]] << "\n\n\n";

	rtn = stream.str();

	return rtn;
}

std::string MadQuests::numToWord(int num)
{
	std::string rtn = " ";
	switch (num)
	{
	case 1:
		rtn = "ONE";
		break;
	case 2:
		rtn = "TWO";
		break;
	case 3:
		rtn = "THREE";
		break;
	case 4:
		rtn = "FOUR";
		break;
	case 5:
		rtn = "FIVE";
	case 6:
		rtn = "SIX";
	}

	return rtn;
}

void MadQuests::MakeUpperCase(std::string& word)
{
	//Here we use a different type of for loop, it is essentially a for each
	//You could read it as "For each character we will call letter in the string word" as we
	//want to change the actual letter in the word we add the & to get the character by reference
	for (char& letter : word)
	{
		letter = std::toupper(letter);
	}
}