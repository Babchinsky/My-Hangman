#include "Game.h"

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