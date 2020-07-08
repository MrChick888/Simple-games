#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

void play_game();

int main()
{
	srand(time(NULL));
	char choice;
	while (true)
	{
		std::cout << "0. Quit" << std::endl;
		std::cout << "1. Play game" << std::endl;
		std::cin >> choice;

		switch (choice)
		{
		case '0':
			system("cls");
			std::cout << "Thanks for playing." << std::endl;
			system("PAUSE");
			return 0;
		case '1':
			play_game();
			break;
		}
	}
}

void play_game()
{
	int random_numer = rand() % 1001;
	std::cout << "Guess a numer: ";
	while (true)
	{
		int guess_numer;
		std::cin >> guess_numer;
		if (guess_numer == random_numer)
		{
			std::cout << "You win!" << std::endl;
			break;
		}
		else if (guess_numer < random_numer)
		{
			std::cout << "Too low" << std::endl;
		}
		else
		{
			std::cout << "Too high" << std::endl;
		}
	}
}