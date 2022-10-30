#include "Game.h"

void PrintHangMan(int iLives)
{

	if (iLives == 7)
	{
		cout << "\t\t +---+\n";
		cout << "\t\t     |\n";
		cout << "\t\t     | \n";
		cout << "\t\t     |\n";
		cout << "\t\t     | \n";
		cout << "\t\t     |\n";
		cout << "\t\t=========\n";
	}
	else if (iLives == 6)
	{
		cout << "\t\t +---+\n";
		cout << "\t\t |   |\n";
		cout << "\t\t     | \n";
		cout << "\t\t     |\n";
		cout << "\t\t     | \n";
		cout << "\t\t     |\n";
		cout << "\t\t=========\n";
	}
	else if (iLives == 5)
	{
		cout << "\t\t +---+\n";
		cout << "\t\t |   |\n";
		cout << "\t\t O   | \n";
		cout << "\t\t     |\n";
		cout << "\t\t     | \n";
		cout << "\t\t     |\n";
		cout << "\t\t=========\n";
	}
	else if (iLives == 4)
	{
		cout << "\t\t +---+\n";
		cout << "\t\t |   |\n";
		cout << "\t\t O   | \n";
		cout << "\t\t |   |\n";
		cout << "\t\t     | \n";
		cout << "\t\t     |\n";
		cout << "\t\t=========\n";
	}
	else if (iLives == 3)
	{
		cout << "\t\t +---+\n";
		cout << "\t\t |   |\n";
		cout << "\t\t O   | \n";
		cout << "\t\t |\\  |\n";
		cout << "\t\t     | \n";
		cout << "\t\t     |\n";
		cout << "\t\t=========\n";
	}
	else if (iLives == 2)
	{
		cout << "\t\t +---+\n";
		cout << "\t\t |   |\n";
		cout << "\t\t O   | \n";
		cout << "\t\t/|\\  |\n";
		cout << "\t\t     | \n";
		cout << "\t\t     |\n";
		cout << "\t\t=========\n";
	}
	else if (iLives == 1)
	{
		cout << "\t\t +---+\n";
		cout << "\t\t |   |\n";
		cout << "\t\t O   | \n";
		cout << "\t\t/|\\  |\n";
		cout << "\t\t  \\  | \n";
		cout << "\t\t     |\n";
		cout << "\t\t=========\n";
	}
	else {
		cout << "\t\t +---+\n";
		cout << "\t\t |   |\n";
		cout << "\t\t O   | \n";
		cout << "\t\t/|\\  |\n";
		cout << "\t\t/ \\  | \n";
		cout << "\t\t     |\n";
		cout << "\t\t=========\n";

	}
}
void ChangeTextColour(int iCoulorValue)
{
	//0 = Black 
	//1 = Blue 
	//2 = Green 
	//3 = Aqua 
	//4 = Red 
	//5 = Purple
	//6 = Yellow 
	//7 = White 

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), iCoulorValue);
}
void ChangeConsoleWindowSize(int iXValue, int iYvalue)
{
	// changes the size of the consloe windows X and Y cordinates 
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);

	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, iXValue, iYvalue, TRUE);

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
set<char> FillAlphabet(set<char> sAlphabet)
{
	//adding letters to alpha 
	for (int i = 97; i <= 122; i++)
	{
		char c = i;
		sAlphabet.insert(i);
	}

	return sAlphabet;
}
void PrintAplhabet(set<char> sAlphabet, set<char> sCorretGuess)
{

	char cLetter;

	cout << "   ";
	for (int i = 97; i <= 122; i++)
	{
		cLetter = i;

		cout << " ";
		if (sAlphabet.find(cLetter) != sAlphabet.end())
		{
			cout << cLetter;
		}
		else if (sCorretGuess.find(cLetter) != sCorretGuess.end())
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
bool IsGuessCorrect(vector<char> vGuess, string word)
{
	bool bLetterInWord = false;
	for (int i = 0; i < word.length(); i++)
	{
		if (vGuess.back() == word[i])
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
void PrintWord(string sWord, vector<char> vPLayerGuss)
{

	//this will print out letters or '_'
	for (int i = 0; i < sWord.length(); i++)
	{
		// if the user has guessed a letter and it is in the Vetor loop will print out the letter
		if (count(vPLayerGuss.begin(), vPLayerGuss.end(), sWord[i]))
		{
			cout << sWord[i];
		}
		// if the user has not guessed that letter loop will print out a '_'
		else
		{
			cout << "_";
		}
	}
}
void PrintGameState(int iLives, string sWord, vector<char> vPLayerGuss)
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

	PrintHangMan(iLives);

	//guess banner 
	ChangeTextColour(2);
	cout << "=============";
	ChangeTextColour(7);
	cout << "<<<Guess>>>";
	ChangeTextColour(2);
	cout << "============\n";
	ChangeTextColour(7);

	cout << "\t\t";
	PrintWord(sWord, vPLayerGuss);
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
void PrintGameOverScreen(int iLives)
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
	PrintHangMan(iLives);
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
void PrintWinScreen(int iLives, string sWord)
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
	PrintHangMan(iLives);
	cout << "\n\t\t" << sWord << "\n";
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
bool CheckIfPlayerHasWon(string sWord, set <char> sCorrectGuesses)
{

	// if all of the letter cant be found in the set player has not won 
	for (int i = 0; i < sWord.length(); i++)
	{

		if (!(sCorrectGuesses.find(sWord[i]) != sCorrectGuesses.end()))
		{
			return false;
		}
	}
	return true;
}


int main()
{
	//collection used 
	vector<char> vGuessedLetters;
	set<char> sCorrectGuess;
	set<char> sRemainingLetters;

	ifstream readFile("words.dat"); // opening text file
	string level, word;             // readed data
	string selected_level;
	unsigned int words_number = 0;

	//testing word 
	string HiddenWord;

	// set up variables 
	int iLives = 7;
	bool bHasPlayerWon = false;



	//Game Loop
	do
	{
		// getting a random number between one and 3 to paick a word
		srand(time(NULL));

		char cDifficulty = Intro();
		sRemainingLetters = FillAlphabet(sRemainingLetters);

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

		HiddenWord = words[iRandomNumber];

		cout << "Hidden: " << HiddenWord << endl;

		do
		{
			PrintGameState(iLives, HiddenWord, vGuessedLetters);
			cout << "\n\n";
			PrintAplhabet(sRemainingLetters, sCorrectGuess);
			// getting letter from user and removing it form Remaining Letters
			bool bDuplicateLetter;
			char cLetter;
			do
			{
				cLetter = GetLetter();
				bDuplicateLetter = CheckDuplicateLetter(sRemainingLetters, cLetter);

			} while (bDuplicateLetter);

			vGuessedLetters.push_back(cLetter);
			sRemainingLetters.erase(vGuessedLetters.back());

			//cheking to see if the user guessed a letter if they guessed worng they lose a life 
			bool bCorrectGuess = IsGuessCorrect(vGuessedLetters, HiddenWord);
			if (bCorrectGuess)
			{
				sCorrectGuess.insert(cLetter);
			}
			else
			{
				iLives--;
			}

			//cheking if player has won the game
			bHasPlayerWon = CheckIfPlayerHasWon(HiddenWord, sCorrectGuess);


		} while (iLives > 0 && !bHasPlayerWon);

		if (bHasPlayerWon)
		{
			PrintWinScreen(iLives, HiddenWord);
		}
		else
		{
			PrintGameOverScreen(iLives);
		}

		//resteting for next game
		sRemainingLetters.clear();
		sCorrectGuess.clear();
		vGuessedLetters.clear();
		iLives = 7;
		delete[] words;
	} while (true); 
}