#include <iostream>

int main()
{
	//This while loop is an infinite loop, in normal circumstances we would not want this, only way to exit is to exit program more 
	//on loops in next project, for now just know everything within its brackets will repeat once over until we close the program
	while (true)
	{
		char playerOneHand;		//Variable to hold player 1s choice
		char playerTwoHand;		//Variable to hold player 2s choice
		bool tie = false;		//Variable to show if there has been a tie
		std::string winner;		//Variable that holds the text of the player that won

		//We prompt player 1 for input
		std::cout << "Player 1 Choose Your Hand(r for rock, p for paper, s for scissors): ";
		std::cin >> playerOneHand;

		//Clear the screen then prompt player 2 for input
		system("cls");
		std::cout << "Player 2 Choose Your Hand(r for rock, p for paper, s for scissors): ";
		std::cin >> playerTwoHand;

		//Clear the screen again
		system("cls");

		//Display what each player chose
		std::cout << "Player 1 chose: " << playerOneHand << " and Player 2 chose: " << playerTwoHand << "\n\n";

		//Next we will find the results using 3 different types of logics, first with just if elses, the with if else and
		//switch statements and finally using only switch statements
#pragma region If Else Logic
		//First we see if player 1 chose rock, we account for a lowercase or (||) an uppercase
		if (playerOneHand == 'r' || playerOneHand == 'R')
		{
			//If the player chose rock see if player 2 chose scissors if so the winner = player 1, note for a single line no need for {}
			if (playerTwoHand == 's' || playerTwoHand == 'S')
				winner = "Player 1";
			//Else if player 2 chose paper the winner is player 2
			else if (playerTwoHand == 'p' || playerTwoHand == 'P')
				winner = "Player 2";
			//If player 1 chose rock and player 2 did not choose scissors or paper they must have chosen rock so its a tie(a future version 
			//will account for invalid input ie input other than r, p, s, for now we assume the user is a good sport with 0 typos
			else
				tie = true;
		}
		//So if player one did not choose rock check to see if they chose paper
		else if (playerOneHand == 'p' || playerOneHand == 'P')
		{
			//Check for win conditions like before but with player 1 being paper now
			if (playerTwoHand == 'r' || playerTwoHand == 'R')
				winner = "Player 1";
			else if (playerTwoHand == 'p' || playerTwoHand == 'P')
				tie = true;
			else
				winner = "Player 2";
		}
		//Player 1 did not chose rock or paper so we assume they chose scissors as the default
		else
		{
			//Check the win conditions like before
			if (playerTwoHand == 'r' || playerTwoHand == 'R')
				winner = "Player 2";
			else if (playerTwoHand == 'p' || playerTwoHand == 'P')
				winner = "Player 1";
			else
				tie = true;
		}

		//If there was a tie we say it was a tie
		if (tie)
		{
			std::cout << "It's a tie!\n\n";
		}
		//Otherwise there must be a winner so we display who won
		else
		{
			std::cout << winner << " wins!\n\n";
		}
#pragma endregion

		//The next block of statements will look similar and they behave similary, we do some things to help our logic though
#pragma region If Switch logic
		//First we make the players inputs be the lowercase version if they werent already, we use std::tolower to achieve this
		playerOneHand = std::tolower(playerOneHand);
		playerTwoHand = std::tolower(playerTwoHand);

		//First we check if player 1 chose rock
		if (playerOneHand == 'r')
		{
			//Now instead of using another if else loop we use something called a switch, it is used for a single variable with
			//Different possible values , here we "switch" on player 2s choice
			switch (playerTwoHand)
			{
				//We first check if player 2 chose rock if so it's a tie! We must put break; at the end of each case otherwise the code
				//Will continue down the line
			case 'r':
				tie = true;
				break;
				//Now we check the case that player 2 chose paper
			case 'p':
				winner = "Player 2";
				break;
				//Finally the default case, if none of the other cases were true this runs, we assume if not rock or paper then scissors
			default:
				winner = "Player 1";
				break;
			}
		}
		//We now check if player 1 chose paper
		else if (playerOneHand == 'p')
		{
			//We switch on player 2s choice like before but this time player 1 chose paper
			switch (playerTwoHand)
			{
			case 'r':
				winner = "Player 1";
				break;
			case 'p':
				tie = true;
				break;
			default:
				winner = "Player 2";
				break;
			}
		}
		//Finally we assume player 1 chose scissors
		else
		{
			//We check for win conditions again
			switch (playerTwoHand)
			{
			case 'r':
				winner = "Player 2";
				break;
			case 'p':
				winner = "Player 1";
				break;
			default:
				tie = true;
				break;
			}
		}

		std::cout << "\n\n\nUsing if and switch statements\n\n";

		if (tie)
		{
			std::cout << "It's a tie!\n\n";
		}
		else
		{
			std::cout << winner << " wins!\n\n";
		}
#pragma endregion

#pragma region Nested Switch
		//Finally we will use only switch statements first we switch on player 1s choice
		switch (playerOneHand)
		{
			//in the case that player 1 chose rock, we will then switch on player 2s choice within this case to check win conditions
		case 'r':
			switch (playerTwoHand)
			{
			case 'r':
				tie = true;
				break;
			case 'p':
				winner = "Player 2";
				break;
			default:
				winner = "Player 1";
				break;
			}
			break;
			//Next up is the case that player 1 chose paper, we then use another switch to check win conditions
		case 'p':
			switch (playerTwoHand)
			{
			case 'r':
				winner = "Player 1";
				break;
			case 'p':
				tie = true;
				break;
			default:
				winner = "Player 2";
				break;
			}
			break;
			//Finally we assume if neither of the other cases were true then player 1 chose scissors, then use a switch to check for wins
		default:
			switch (playerTwoHand)
			{
			case 'r':
				winner = "Player 2";
				break;
			case 'p':
				winner = "Player 1";
				break;
			default:
				tie = true;
				break;
			}
			break;
		}


		std::cout << "\n\n\nUsing nested switch statements\n\n";

		if (tie)
		{
			std::cout << "It's a tie!\n\n";
		}
		else
		{
			std::cout << winner << " wins!\n\n";
		}
#pragma endregion
	}
	
	return 0;
}