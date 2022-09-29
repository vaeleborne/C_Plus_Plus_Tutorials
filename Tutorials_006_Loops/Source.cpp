#include <iostream>

int main()
{
	char replay = 'n';	//Variable used to determine if program should run again

	//We loop the majority of the program within a do while loop, this is similar to a while loop except it runs at least once
	do
	{
		system("cls");	//Clear the console, helpful if program runs again to get a clear start

		//Variable to be used in a while loop to show while iterations
		int i = 0;
		std::cout << "Lets count to 15 with a while loop!\n\n";		//We tell the user what we are going to do

		//The code within this while loop will run as long as i <= 15 we must iterate i within it to avoid an infinite loop
		while (i <= 15)
		{
			std::cout << i;		//Display the current value of i

			//As long as i is not 15 add ... after the number for display purposes
			if(i !=15)
				std::cout << "...";
			i++; //same as i = i + 1 can also use -- for i = i - 1
		}

		//Now we will do the same thing(count to 15 and display) but using a for loop which is more suited for a set number of iterations
		std::cout << "\n\n\nNow with a for loop: \n\n";
		//The code within this loop will run 15 times, j starts at 0 and automatically increases at the end, it will run as long as j < 16
		for (int j = 0; j < 16; j++)
		{
			std::cout << j;
			if (j != 15)
				std::cout << "...";
			//no need to iterate j here as the loop does it itself as we put j++, but what would happend if we put ++j?
		}

		//Same as previous loop only ++j rather than j++
		std::cout << "\n\n\nLet's see what happens if we put ++ before j instead of after:\n\n";
		for (int j = 0; j < 16; ++j)
		{
			std::cout << j;
			if (j != 15)
				std::cout << "...";
		}

		//Display to the user what is going on and what we are going to do next
		std::cout << "\n\nIt looks the same so what's the difference? Well lets use them in a different context\n\n" 
					<< "x = 1 and y = 1, x++ - ++y = ";

		//We set two different variables to the same value 1
		int x = 1;
		int y = 1;

		//We display a version of x - y then the new values of x and y as ++ or -- does change the value of a variable
		//x++ - ++y becomes 1++ - ++1 the next step for the computer is to change the ++1 so it gets
		//1++ - 2, since 1++ has the iteration after it does the equation first 1-2 = -1 now that 
		// that is done it will iterate our x value to 2 so both x an y = 2 now but x++ - ++y was = -1 due to order of operations
		std::cout << x++ - ++y << " now the values of x and y have also changed. X = " << x << " Y = " << y;

		//Display a simple explanation to the user
		std::cout << "\n\nAs you can see both end up the same value, however putting the iterator before causes it to happen first if\n"
			<< "it is in a statement.";

		//Prompt user to run the program again
		std::cout << "\n\n\n\nWould you like to run the program again? (y/n) : ";
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> replay;
	} while (replay == 'y');

	return 0; 
}

//NEXT UP - Mini Project - Multiplication Calculator but use only addition and a loop of your choice

