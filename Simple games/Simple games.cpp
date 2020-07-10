#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <vector>
#include <fstream>
#include <Windows.h>

void leave_game();
void print_guesses(std::vector<int> data);
void play_guessing_game();

char draw_color();
void play_casino_game();

int main()
{
	srand(time(NULL));
	char choice;
	while (true)
	{
		//menu function
		std::cout << "0. Quit" << std::endl;
		std::cout << "1. Play guessing game" << std::endl;
		std::cout << "2. Play casino game" << std::endl;
		choice = _getch();

		switch (choice)
		{
		case '0':
			leave_game();
			break;
		case '1':
			play_guessing_game();
			break;
		case '2':
			play_casino_game();
			break;
		default:
			system("cls");
			std::cout << "This character is incorrect!" << std::endl;
			system("PAUSE");
			system("cls");
			break;
		}
	}
}

void leave_game()
{
	system("cls");
	char leave;
	while (true)
	{
		std::cout << "Are you sure You want to leave? (Y/N)" << std::endl;
		leave = _getch();
		if (leave == 'Y' || leave == 'y')
		{
			system("cls");
			std::cout << "Thanks for playing." << std::endl;
			system("PAUSE");
			exit(0);
		}
		else if (leave == 'N' || leave == 'n')
		{
			std::cout << "Ooo it's really nice" << std::endl;
			system("PAUSE");
			system("cls");
			break;
		}
		else
		{
			system("cls");
			std::cout << "This character is incorrect!" << std::endl;
		}
	}
}

void print_guesses(std::vector<int> data)
{
	for (int i = 0; i < data.size(); i++)
	{
		std::cout << data[i] << "\t";
	}
	std::cout << std::endl;
}

void play_guessing_game()
{
	std::vector<int> guesses;
	int random_numer = rand() % 1000 + 1;
	system("cls");
	std::cout << "Guess a numer (1-1000): ";
	while (true)
	{
		int guess_numer;
		std::cin >> guess_numer;
		guesses.push_back(guess_numer);
		if (guess_numer == random_numer)
		{
			system("cls");
			std::cout << guess_numer << " is correct. You win!" << std::endl;
			std::cout << "Your guesses:" << std::endl;
			print_guesses(guesses);
			system("PAUSE");
			system("cls");
			break;
		}
		else if (guess_numer < random_numer)
		{
			std::cout << guess_numer << " is too low" << std::endl;
		}
		else
		{
			std::cout << guess_numer << " is too high" << std::endl;
		}
		std::cout << "Try again! Guess another numer (1-1000): ";
	}
}

char draw_color()
{
	int random_numer = rand() % 100 + 1;
	char color;
	if (random_numer <= 47)
	{
		color = 'R';
	}
	else if (random_numer <= 54)
	{
		color = 'B';
	}
	else
	{
		color = 'G';
	}
	return color;
}

void play_casino_game()
{
	system("cls");
	char correct_color;
	char player_color;
	correct_color = draw_color();

	std::string player_name;
	std::cout << "Enter your name: ";
	std::cin >> player_name;
	std::string player_surname;
	std::cout << "Enter your surname: ";
	std::cin >> player_surname;
	std::string file_name = player_name + player_surname;
	std::fstream save(file_name + ".txt");

	long double balans = 100;
	save >> balans;
	system("cls");
	std::cout<<"Hello "<<player_name<<" "<<player_surname<<", You have " << balans << " credits." << std::endl;

	do
	{
		std::cout << "Pick the color (R|G|B): ";
		std::cin >> player_color;
		if ((player_color != 'R') && (player_color != 'G') && (player_color != 'B'))
		{
			std::cout << "This character is incorrect!" << std::endl;
			system("PAUSE");
			system("cls");
		}

	}while ((player_color != 'R') && (player_color != 'G') && (player_color != 'B'));

	system("cls");
	
	for (int i = 5; i >= 0; i--)
	{
		std::cout << i;
		Sleep(1000);
		system("cls");
	}
	system("PAUSE");
	system("cls");
}
