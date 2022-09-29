#include <iostream>
#include <string>
#include <sstream>

/*Function clears cin of any errors it may have then ignores the current available
buffer to ensure next input is fresh*/
void ClearCin();

/*Main game function, plays a simple two player game of Rock Paper Scissors*/
void RockPaperScissors();

/*Simple function to check for a tie, returns true if p1 = p2*/
bool IsTie(char p1, char p2);

/*Function to demonstrate default values, will display the string passed in with a line
break at the end, or if nothing is passed to the function will display the welcome message*/
void DisplayMessage(std::string message = "Welcome To A 'Functional' Rock Paper Scissors!");

/*Function will return a string that has the results of the game, who won or if it was a tie*/
std::string GetResultStatement(char p1, char p2);

/*Will convert the users single character input to the appropriate word ie r will return Rock, 
p Paper, s Scissors*/
std::string CharToString(char sign);

int main()
{ 
	char play = 'n';	//Variable to determine if game should be played again, default value of n for no

	//We use a do while loop to run the game at least once, at the end we prompt the user to see if they wish to play again
	do
	{
		system("cls");
		RockPaperScissors();
		std::cout << "\n\nWould you like to play again? (y/n): ";
		ClearCin();
		std::cin >> play;
		play = std::tolower(play);
	} while (play == 'y');

	return 0;
}

void ClearCin()
{
	std::cin.clear();		//Clears cin of any error codes
	std::cin.ignore(std::cin.rdbuf()->in_avail());		//If anything is in the cin buffer this will ignore it
}

bool IsTie(char p1, char p2)
{
	bool rtn = false;	//The return variable

	if (p1 == p2)
		rtn = true;		//If p1 = p2 we set the return to be true

	return rtn;
}

void DisplayMessage(std::string message)
{
	std::cout << message << "\n";	//Write the message passed or the default message to the console with a line break at the end
}

std::string GetResultStatement(char p1, char p2)
{
	std::string rtn = "";		//The return variable
	std::stringstream stream;	//A string stream, it behaves similar to cout but instead of writing to the console we write to the variable
	
	//Here we make the users input be lowercase for easier checking
	p1 = std::tolower(p1);
	p2 = std::tolower(p2);

	//We write the users inputs into the stringstream variable, eventually we will convert it to a single string
	stream << "\n\nPlayer one chose " << CharToString(p1) << " and Player 2 chose " << CharToString(p2) << "\n\n";



	if (IsTie(p1, p2))
	{
		stream << "It's a tie!\n\n";	//If the game is a tie we add the tie message to the stream
	}
	else
	{
		if (p1 == 'r' && p2 == 's' || p1 == 'p' && p2 == 'r' || p1 == 's' && p2 == 'p')
			stream << "Player 1 Wins!\n\n";		//If statement checks for all possible win conditions for player 1 and updates stream
		else
			stream << "Player 2 Wins!\n\n";		//At this point, it's not a tie and player 1 did not win so update stream for p2 win
	}

	rtn = stream.str();		//We get the single string that is in the stream and set our return value to be equal to it
	return rtn;
}

void RockPaperScissors()
{
	//Initialize the variables representing the players choices
	char playerOneHand = ' ';
	char playerTwoHand = ' ';

	//Display the welcome message
	DisplayMessage();

	//Get player 1s choice
	std::cout << "\n\nPlayer 1, please enter your choice (r for rock, p for paper, s for scissors) : ";
	ClearCin();
	std::cin >> playerOneHand;

	//Clear the console, display the welcome message again then get player 2s choice
	system("cls");
	DisplayMessage();
	std::cout << "\n\nPlayer 2, please enter your choice (r for rock, p for paper, s for scissors) : ";
	ClearCin();
	std::cin >> playerTwoHand;

	//Display the results of the game
	DisplayMessage(GetResultStatement(playerOneHand, playerTwoHand));
}

std::string CharToString(char sign)
{
	std::string rtn = "";

	//We use a switch statement to set the return variable equal to the appropriate string
	switch (sign)
	{
	case 'r':
		rtn = "Rock";
		break;
	case 'p':
		rtn = "Paper";
		break;
	case 's':
		rtn = "Scissors";
		break;
	default:
		break;
	}
	return rtn;
}
