#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <vector>
#include <fstream>
#include <Windows.h>
#include <fstream>

void leave_game();
void main_menu();

void best_score_guesses(std::vector<int>);
void print_guesses(std::vector<int>);
void play_guessing_game();

char draw_color();
long double bet_casino(long double);
char player_color_casiono();
void counter_casino();
long double verdict_casino(char,char,long double,long double);
void play_casino_game();

int main()
{
	srand(time(NULL));
	char choice;
	while (true)
	{
		main_menu();
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

void main_menu()
{
	std::cout << "0. Quit" << std::endl;
	std::cout << "1. Play guessing game" << std::endl;
	std::cout << "2. Play casino game" << std::endl;
	std::cout << "Make your chooise: ";
}

void best_score_guesses(std::vector<int> data)
{
	std::ifstream guess_input("D:/Programowanie/GitHub/Simple games/Simple games/Guessing_game/Guesses_best_score.txt");
	int best_score;
	guess_input >> best_score;
	std::ofstream guess_output("D:/Programowanie/GitHub/Simple games/Simple games/Guessing_game/Guesses_best_score.txt");
	std::cout << "You won in " << data.size() << " moves." << std::endl;
	if (data.size() < best_score)
	{
		guess_output << data.size();
		std::cout << "It is a new best score! The old one was: " << best_score << std::endl << std::endl;
	}
	else if (data.size() == best_score)
	{
		guess_output << best_score;
		std::cout << "Great job, You just align the best score (" << best_score << ")." << std::endl << std::endl;
	}
	else
	{
		guess_output << best_score;
		std::cout << "So close, current best score: " << best_score << std::endl << std::endl;
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
			std::cout << guess_numer << " is correct." << std::endl;
			best_score_guesses(guesses);
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

long double bet_casino(long double balans)
{
	long double bet;
	while (true)
	{
		std::cout << "Enter an amout of credits to bet: ";
		std::cin >> bet;
		if (bet > balans)
		{
			std::cout << "You don't have enought credits! Try again" << std::endl;
			system("PAUSE");
			system("cls");
		}
		else if (bet <= 0)
		{
			std::cout << "You can't bet " << bet << " credits! Try again" << std::endl;
			system("PAUSE");
			system("cls");
		}
		else
		{
			return bet;
		}
	}
}

char player_color_casiono()
{
	char player_color;
	while (true)
	{
		std::cout << "Pick the color (R|G|B): ";
		std::cin >> player_color;
		player_color = std::toupper(player_color);
		if (player_color != 'R' && player_color != 'G' && player_color != 'B')
		{
			std::cout << "This character is incorrect!" << std::endl;
			system("PAUSE");
			system("cls");
		}
		else
		{
			system("cls");
			return player_color;
		}
	}
}

void counter_casino()
{
	for (int i = 5; i >= 0; i--)
	{
		std::cout << i;
		Sleep(1000);
		system("cls");
	}
}

long double verdict_casino(char correct_color, char player_color, long double balans, long double bet)
{
	if (player_color == correct_color)
	{
		if (player_color == 'R' || player_color == 'B')
		{
			std::cout << "Congratulations You won " << 2 * bet << " credits" << std::endl;
			balans += 2 * bet;
		}
		else if (player_color == 'G')
		{
			std::cout << "Congratulations You won " << 14 * bet << " credits" << std::endl;
			balans += 14 * bet;
		}
	}
	else
	{
		std::cout << "Unfortunately You lost " << bet << " credits" << std::endl;
		std::cout << "The correct color was " << correct_color << std::endl;
	}
	std::cout << "Your current balans: " << balans << std::endl;
	return balans;
}

void play_casino_game()
{
	system("cls");
	char correct_color;
	correct_color = draw_color();

	std::string player_name;
	std::cout << "Enter your name: ";
	std::cin >> player_name;
	std::string player_surname;
	std::cout << "Enter your surname: ";
	std::cin >> player_surname;
	std::string file_name = player_name + player_surname;
	std::cout << file_name;
	std::ifstream save_input("D:/Programowanie/GitHub/Simple games/Simple games/Casino_game/" + file_name + ".txt");
	long double balans = 100;
	save_input >> balans;
	system("cls");
	std::cout << "Hello " << player_name << " " << player_surname << ", You have " << balans << " credits." << std::endl;

	long double bet = bet_casino(balans);
	balans -= bet;

	char player_color = player_color_casiono();

	counter_casino();

	balans=verdict_casino(correct_color, player_color, balans, bet);

	std::ofstream save_output("D:/Programowanie/GitHub/Simple games/Simple games/Casino_game/" + file_name + ".txt");
	save_output << balans;
	system("PAUSE");
	system("cls");
}
