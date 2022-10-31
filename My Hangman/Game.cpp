#include "Game.h"


void PrintHangMan(int lives, int color)
{
	if (lives == 7)
	{
		ChangeTextColor(YELLOW);
		cout << "\t7/7\t";
		ChangeTextColor(color);
		cout << " +---+\n";
		cout << "\t\t     | \n";
		cout << "\t\t     | \n";
		cout << "\t\t     |\n";
		cout << "\t\t     | \n";
		cout << "\t\t     |\n";
		cout << "\t\t=========\n";
	}
	else if (lives == 6)
	{
		ChangeTextColor(YELLOW);
		cout << "\t6/7\t";
		ChangeTextColor(color);
		cout << " +---+\n";
		cout << "\t\t |   |\n";
		cout << "\t\t     | \n";
		cout << "\t\t     |\n";
		cout << "\t\t     | \n";
		cout << "\t\t     |\n";
		cout << "\t\t=========\n";
	}
	else if (lives == 5)
	{
		ChangeTextColor(YELLOW);
		cout << "\t5/7\t";
		ChangeTextColor(color);
		cout << " +---+\n";
		cout << "\t\t |   |\n";
		cout << "\t\t O   | \n";
		cout << "\t\t     |\n";
		cout << "\t\t     | \n";
		cout << "\t\t     |\n";
		cout << "\t\t=========\n";
	}
	else if (lives == 4)
	{
		ChangeTextColor(YELLOW);
		cout << "\t4/7\t";
		ChangeTextColor(color);
		cout << " +---+\n";
		cout << "\t\t |   |\n";
		cout << "\t\t O   | \n";
		cout << "\t\t |   |\n";
		cout << "\t\t     | \n";
		cout << "\t\t     |\n";
		cout << "\t\t=========\n";
	}
	else if (lives == 3)
	{
		ChangeTextColor(YELLOW);
		cout << "\t3/7\t";
		ChangeTextColor(color);
		cout << " +---+\n";
		cout << "\t\t |   |\n";
		cout << "\t\t O   | \n";
		cout << "\t\t |\\  |\n";
		cout << "\t\t     | \n";
		cout << "\t\t     |\n";
		cout << "\t\t=========\n";
	}
	else if (lives == 2)
	{
		ChangeTextColor(YELLOW);
		cout << "\t2/7\t";
		ChangeTextColor(color);
		cout << " +---+\n";
		cout << "\t\t |   |\n";
		cout << "\t\t O   | \n";
		cout << "\t\t/|\\  |\n";
		cout << "\t\t     | \n";
		cout << "\t\t     |\n";
		cout << "\t\t=========\n";
	}
	else if (lives == 1)
	{
		ChangeTextColor(YELLOW);
		cout << "\t1/7\t";
		ChangeTextColor(color);
		cout << " +---+\n";
		cout << "\t\t |   |\n";
		cout << "\t\t O   | \n";
		cout << "\t\t/|\\  |\n";
		cout << "\t\t  \\  | \n";
		cout << "\t\t     |\n";
		cout << "\t\t=========\n";
	}
	else {
		ChangeTextColor(RED);
		cout << "\t0/7\t";
		cout << " +---+\n";
		cout << "\t\t |   |\n";
		cout << "\t\t O   | \n";
		cout << "\t\t/|\\  |\n";
		cout << "\t\t/ \\  | \n";
		cout << "\t\t     |\n";
		cout << "\t\t=========\n";

	}
}
char Intro()
{
	system("cls");

	// printing the intro mesage to the screen
	ChangeConsoleWindowSize(550, 150);
	ChangeTextColor(2);
	cout << "==================================================";
	ChangeTextColor(7);
	cout << "\n\n	   Hello and Welcome to Hangman" << "\n";
	cout << "	   Press any key to continue..." << "\n\n";
	ChangeTextColor(2);
	cout << "==================================================";

	_getch();
	system("cls");

	//top banner 
	ChangeConsoleWindowSize(350, 200);
	ChangeTextColor(2);
	cout << "=========";
	ChangeTextColor(7);
	cout << "<<<HANGMAN>>>";
	ChangeTextColor(2);
	cout << "========\n";
	ChangeTextColor(7);

	//menu text
	cout << "\n\t\b\b\bPlease select difficulty" << "\n";
	cout << "	1) Easy" << "\n";
	cout << "	2) Medium" << "\n";
	cout << "	3) Hard" "\n\n";

	//bottom banner 
	ChangeTextColor(2);
	cout << "=========";
	ChangeTextColor(7);
	cout << "<<<HANGMAN>>>";
	ChangeTextColor(2);
	cout << "========\n";
	ChangeTextColor(7);

	// getting the dificuly the play has selected 
	char difficulty = 0;
	do
	{
		difficulty = _getch();
	} while (difficulty != '1' && difficulty != '2' && difficulty != '3');

	system("cls");
	return difficulty;

}
set<char> FillAlphabet(set<char> alphabet)
{
	//adding letters to alpha 
	for (int i = 97; i <= 122; i++)
	{
		char c = i;
		alphabet.insert(i);
	}

	return alphabet;
}
void PrintAplhabet(set<char> alphabet, set<char> correct_guess)
{

	char letter;

	cout << "   ";
	for (int i = 97; i <= 122; i++)
	{
		letter = i;

		cout << " ";
		if (alphabet.find(letter) != alphabet.end())
		{
			cout << letter;
		}
		else if (correct_guess.find(letter) != correct_guess.end())
		{
			ChangeTextColor(3);
			cout << letter;
			ChangeTextColor(7);
		}
		else
		{
			ChangeTextColor(4);
			cout << letter;
			ChangeTextColor(7);
		}

		if (i == 111)
		{
			cout << "\n       ";
		}
	}
}
char GetLetter()
{
	bool is_letter = false;
	char letter;
	do
	{
		letter = _getch();
		// making sure the char inputed is a letter 
		if (letter >= 'a' && letter <= 'z' || letter >= 'A' && letter <= 'Z')
		{
			is_letter = true;
		}
	} while (!is_letter);

	return letter;
}
bool CheckDuplicateLetter(set<char> list_of_letters, char cletter)
{
	// if the letter is in the <set>list it means the user has not picked that letter 
	if (list_of_letters.find(cletter) != list_of_letters.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool IsGuessCorrect(vector<char> guess, string word)
{
	bool letter_in_word = false;
	for (int i = 0; i < word.length(); i++)
	{
		if (guess.back() == word[i])
		{
			letter_in_word = true;
		}
	}

	if (letter_in_word)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void PrintWord(string word, vector<char> player_guess, char difficulty)
{
	switch (difficulty)
	{
	case EASY:
		cout << " ";
		break;
	case MEDIUM:
		cout << "";
		break;
	case HARD:
		cout << "\b\b";
		break;
	}
	
	//this will print out letters or '_'
	for (int i = 0; i < word.length(); i++)
	{

		// if the user has guessed a letter and it is in the Vetor loop will print out the letter
		if (count(player_guess.begin(), player_guess.end(), word[i]))
		{
			cout << word[i];
		}
		// if the user has not guessed that letter loop will print out a '_'
		else
		{
			cout << "_";
		}
	}
}
void PrintGameState(int lives, string word, vector<char> player_guess, char difficulty)
{
	system("cls");

	//top banner 
	ChangeConsoleWindowSize(410, 300);
	ChangeTextColor(2);
	cout << "============";
	ChangeTextColor(7);
	cout << "<<<HANGMAN>>>";
	ChangeTextColor(2);
	cout << "============\n";
	ChangeTextColor(7);

	PrintHangMan(lives, WHITE);

	//guess banner 
	ChangeTextColor(2);
	cout << "=============";
	ChangeTextColor(7);
	cout << "<<<Guess>>>";
	ChangeTextColor(2);
	cout << "============\n";
	ChangeTextColor(7);

	cout << "\t\t";
	PrintWord(word, player_guess, difficulty);
	cout << "\n";

	//guess banner 
	ChangeTextColor(2);
	cout << "=============";
	ChangeTextColor(7);
	cout << "<<<Guess>>>";
	ChangeTextColor(2);
	cout << "============\n";
	ChangeTextColor(7);
}


void PrintGameOverScreen(int lives, string word, char difficulty, time_t start_seconds)
{
	system("cls");
	ChangeConsoleWindowSize(410, 250);

	time_t end_seconds = time(NULL);
	time_t dif_seconds = end_seconds - start_seconds;


	time_t seconds = dif_seconds;
	time_t minutes;

	minutes = seconds / 60;
	seconds = seconds % 60;

	//top banner 
	ChangeTextColor(2);
	cout << "=======";
	ChangeTextColor(7);
	cout << "<<<GAMEOVER FOR " << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << ">>>";
	ChangeTextColor(2);
	cout << "======\n";
	ChangeTextColor(7);

	ChangeTextColor(4);
	PrintHangMan(lives, RED);
	switch (difficulty)
	{
	case EASY:
		cout << "\n\t\t  " << word << "\n";
		break;
	case MEDIUM:
		cout << "\n\t\t" << word << "\n";
		break;
	case HARD:
		cout << "\n\t\t" << word << "\n";
		break;
	}
	ChangeTextColor(7);

	//guess banner 
	ChangeTextColor(2);
	cout << "==========";
	ChangeTextColor(7);
	cout << "<<<Press Any Key>>>";
	ChangeTextColor(2);
	cout << "========";
	ChangeTextColor(7);

	_getch();
}
void PrintWinScreen(int lives, string word, char difficulty, time_t start_seconds)
{
	system("cls");
	ChangeConsoleWindowSize(410, 250);

	time_t end_seconds = time(NULL);
	time_t dif_seconds = end_seconds - start_seconds;
	

	time_t seconds = dif_seconds;
	time_t minutes;

	minutes = seconds / 60;
	seconds = seconds % 60;


	//top banner 
	ChangeTextColor(2);
	cout << "=======";
	ChangeTextColor(7);
	cout << "<<<YOU WIN FOR "  << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << ">>>";
	ChangeTextColor(2);
	cout << "=======\n";
	ChangeTextColor(7);

	ChangeTextColor(3);
	PrintHangMan(lives, AQUA);

	switch (difficulty)
	{
	case '1':
		cout << "\n\t\t  " << word << "\n";
		break;
	case '2':
		cout << "\n\t\t" << word << "\n";
		break;
	case HARD:
		cout << "\n\t\t" << word << "\n";
		break;
	}
	
	ChangeTextColor(7);

	//guess banner 
	ChangeTextColor(2);
	cout << "==========";
	ChangeTextColor(7);
	cout << "<<<Press Any Key>>>";
	ChangeTextColor(2);
	cout << "========";
	ChangeTextColor(7);



	_getch();
}


bool CheckIfPlayerHasWon(string word, set <char> correct_guesses)
{

	// if all of the letter cant be found in the set player has not won 
	for (int i = 0; i < word.length(); i++)
	{

		if (!(correct_guesses.find(word[i]) != correct_guesses.end()))
		{
			return false;
		}
	}
	return true;
}


void ChangeTextColor(int color_value)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_value);
}
void ChangeConsoleWindowSize(int x_value, int y_value)
{
	// changes the size of the consloe windows X and Y cordinates 
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);

	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, x_value, y_value, TRUE);
}

