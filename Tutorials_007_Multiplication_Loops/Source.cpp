#include<iostream>

int main()
{
	//Variables to be used
	int x; 
	int y;
	int ans;

	//Prompt for x
	std::cout << "Enter the number to be multiplied: ";
	std::cin >> x;

	//Prompt for y
	std::cout << "\nEnter the other number: ";
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin >> y;

	//Set the current value of the answer to x
	ans = x;
	//We want to loop y times to add x to itself so we get the multiplicative result. Remember i starts at 0 so we want i to be < y - 1
	for (int i = 0; i < y - 1; i++)
	{
		ans += x;	//ans += x is equivalent to ans = answer + x
	}

	//Display the results
	std::cout << "\n\n" << x << " x " << y << " = " << ans << "\n";
	return 0;
}