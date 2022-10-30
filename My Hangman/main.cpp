#include "Game.h"

int main()
{
	//collection used 
	vector<char> guessed_letters;
	set<char> correct_guess;
	set<char> remaining_letters;

	ifstream readFile("words.dat"); // opening text file
	string level, word;             // readed data
	string selected_level;
	unsigned int words_number = 0;

	//testing word 
	string hidden_word;

	// set up variables 
	int lives = 7;
	bool has_player_won = false;



	//Game Loop
	do
	{
		// getting a random number between one and 3 to paick a word
		srand(time(NULL));

		char cDifficulty = Intro();
		remaining_letters = FillAlphabet(remaining_letters);

		//picking the word
		switch (cDifficulty)
		{
		case '1':
			selected_level = "easy";
			break;
		case '2':
			selected_level = "medium";
			break;
		case '3':
			selected_level = "hard";
			break;
		}


		// count numbers of difficult words
		while (readFile >> level >> word)
			if (level == selected_level)
				words_number++;
		readFile.close();




		// create array with with correct size
		string* words = new string[words_number];

		// add correct words to array
		ifstream readFile("words.dat"); // opening text file
		int i = 0;

		while (readFile >> level >> word)
			if (level == selected_level)
				words[i++] = word;

		readFile.close();

		int iRandomNumber = rand() % words_number;

		hidden_word = words[iRandomNumber];

		cout << "Hidden: " << hidden_word << endl;

		do
		{
			PrintGameState(lives, hidden_word, guessed_letters);
			cout << "\n\n";
			PrintAplhabet(remaining_letters, correct_guess);
			// getting letter from user and removing it form Remaining Letters
			bool bDuplicateLetter;
			char cLetter;
			do
			{
				cLetter = GetLetter();
				bDuplicateLetter = CheckDuplicateLetter(remaining_letters, cLetter);

			} while (bDuplicateLetter);

			guessed_letters.push_back(cLetter);
			remaining_letters.erase(guessed_letters.back());

			//cheking to see if the user guessed a letter if they guessed worng they lose a life 
			bool bCorrectGuess = IsGuessCorrect(guessed_letters, hidden_word);
			if (bCorrectGuess)
			{
				correct_guess.insert(cLetter);
			}
			else
			{
				lives--;
			}

			//cheking if player has won the game
			has_player_won = CheckIfPlayerHasWon(hidden_word, correct_guess);


		} while (lives > 0 && !has_player_won);

		if (has_player_won)
		{
			PrintWinScreen(lives, hidden_word);
		}
		else
		{
			PrintGameOverScreen(lives, hidden_word);
		}

		//resteting for next game
		remaining_letters.clear();
		correct_guess.clear();
		guessed_letters.clear();
		lives = 7;
		delete[] words;
	} while (true);
}




void PrintHangMan(int lives, int color)
{
	if (lives == 7)
	{
		ChangeTextColour(YELLOW);
		cout << "\t0/7\t";
		ChangeTextColour(color);
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
		ChangeTextColour(YELLOW);
		cout << "\t1/7\t";
		ChangeTextColour(color);
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
		ChangeTextColour(YELLOW);
		cout << "\t2/7\t";
		ChangeTextColour(color);
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
		ChangeTextColour(YELLOW);
		cout << "\t3/7\t";
		ChangeTextColour(color);
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
		ChangeTextColour(YELLOW);
		cout << "\t4/7\t";
		ChangeTextColour(color);
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
		ChangeTextColour(YELLOW);
		cout << "\t5/7\t";
		ChangeTextColour(color);
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
		ChangeTextColour(YELLOW);
		cout << "\t6/7\t";
		ChangeTextColour(color);
		cout << " +---+\n";
		cout << "\t\t |   |\n";
		cout << "\t\t O   | \n";
		cout << "\t\t/|\\  |\n";
		cout << "\t\t  \\  | \n";
		cout << "\t\t     |\n";
		cout << "\t\t=========\n";
	}
	else {
		ChangeTextColour(RED);
		cout << "\t7/7\t";
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
	ChangeTextColour(2);
	cout << "==================================================";
	ChangeTextColour(7);
	cout << "\n\n	   Hello and Welcome to Hangman" << "\n";
	cout << "	   Pres any key to continue..." << "\n\n";
	ChangeTextColour(2);
	cout << "==================================================";

	_getch();
	system("cls");

	//top banner 
	ChangeConsoleWindowSize(350, 200);
	ChangeTextColour(2);
	cout << "=========";
	ChangeTextColour(7);
	cout << "<<<HANGMAN>>>";
	ChangeTextColour(2);
	cout << "========\n";
	ChangeTextColour(7);

	//menu text
	cout << "\nPlease select your dificulty" << "\n";
	cout << "	1) Easy" << "\n";
	cout << "	2) Medium" << "\n";
	cout << "	3) Hard" "\n\n";

	//bottom banner 
	ChangeTextColour(2);
	cout << "=========";
	ChangeTextColour(7);
	cout << "<<<HANGMAN>>>";
	ChangeTextColour(2);
	cout << "========\n";
	ChangeTextColour(7);

	// getting the dificuly the play has selected 
	char cDificulty = 0;
	do
	{
		cDificulty = _getch();
	} while (cDificulty != '1' && cDificulty != '2' && cDificulty != '3');

	system("cls");
	return cDificulty;

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

	char cLetter;

	cout << "   ";
	for (int i = 97; i <= 122; i++)
	{
		cLetter = i;

		cout << " ";
		if (alphabet.find(cLetter) != alphabet.end())
		{
			cout << cLetter;
		}
		else if (correct_guess.find(cLetter) != correct_guess.end())
		{
			ChangeTextColour(3);
			cout << cLetter;
			ChangeTextColour(7);
		}
		else
		{
			ChangeTextColour(4);
			cout << cLetter;
			ChangeTextColour(7);
		}

		if (i == 111)
		{
			cout << "\n       ";
		}
	}
}
char GetLetter()
{
	bool bIsletter = false;
	char cLetter;
	do
	{
		cLetter = _getch();
		// making sure the char inputed is a letter 
		if (cLetter >= 'a' && cLetter <= 'z' || cLetter >= 'A' && cLetter <= 'Z')
		{
			bIsletter = true;
		}
	} while (!bIsletter);

	return cLetter;
}
bool CheckDuplicateLetter(set<char> sListOfLetters, char cletter)
{
	// if the letter is in the <set>list it means the user has not picked that letter 
	if (sListOfLetters.find(cletter) != sListOfLetters.end())
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
	bool bLetterInWord = false;
	for (int i = 0; i < word.length(); i++)
	{
		if (guess.back() == word[i])
		{
			bLetterInWord = true;
		}
	}

	if (bLetterInWord)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void PrintWord(string word, vector<char> player_guess)
{
	cout << "  ";
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
void PrintGameState(int lives, string word, vector<char> player_guess)
{
	system("cls");

	//top banner 
	ChangeConsoleWindowSize(410, 300);
	ChangeTextColour(2);
	cout << "============";
	ChangeTextColour(7);
	cout << "<<<HANGMAN>>>";
	ChangeTextColour(2);
	cout << "============\n";
	ChangeTextColour(7);

	PrintHangMan(lives, WHITE);

	//guess banner 
	ChangeTextColour(2);
	cout << "=============";
	ChangeTextColour(7);
	cout << "<<<Guess>>>";
	ChangeTextColour(2);
	cout << "============\n";
	ChangeTextColour(7);

	cout << "\t\t";
	PrintWord(word, player_guess);
	cout << "\n";

	//guess banner 
	ChangeTextColour(2);
	cout << "=============";
	ChangeTextColour(7);
	cout << "<<<Guess>>>";
	ChangeTextColour(2);
	cout << "============\n";
	ChangeTextColour(7);




}
void PrintGameOverScreen(int lives, string word)
{
	system("cls");
	ChangeConsoleWindowSize(410, 250);

	//top banner 
	ChangeTextColour(2);
	cout << "=============";
	ChangeTextColour(7);
	cout << "<<<GAMEOVER>>>";
	ChangeTextColour(2);
	cout << "==========\n";
	ChangeTextColour(7);

	ChangeTextColour(4);
	PrintHangMan(lives, RED);
	cout << "\n\t\t  " << word << "\n";
	ChangeTextColour(7);

	//guess banner 
	ChangeTextColour(2);
	cout << "==========";
	ChangeTextColour(7);
	cout << "<<<Press Any Key>>>";
	ChangeTextColour(2);
	cout << "========";
	ChangeTextColour(7);
	_getch();
}
void PrintWinScreen(int lives, string word)
{
	system("cls");
	ChangeConsoleWindowSize(410, 250);

	//top banner 
	ChangeTextColour(2);
	cout << "=============";
	ChangeTextColour(7);
	cout << "<<<YOU WIN>>>";
	ChangeTextColour(2);
	cout << "==========\n";
	ChangeTextColour(7);

	ChangeTextColour(3);
	PrintHangMan(lives, AQUA);
	cout << "\n\t\t  " << word << "\n";
	ChangeTextColour(7);

	//guess banner 
	ChangeTextColour(2);
	cout << "==========";
	ChangeTextColour(7);
	cout << "<<<Press Any Key>>>";
	ChangeTextColour(2);
	cout << "========";
	ChangeTextColour(7);
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




void ChangeTextColour(int color_value)
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