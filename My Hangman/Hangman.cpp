#include "Hangman.h"

Hangman::Hangman()
{
	words_number = 0;
	lives = 7;
	has_player_won = false;
}

void Hangman::GameLoop()
{
	time_t start_seconds;
	ifstream readFile("words.dat"); // opening text file
	//Game Loop
	do
	{
		// getting a random number between one and 3 to paick a word
		srand(time(NULL));

		char difficulty = Intro();
		remaining_letters = FillAlphabet(remaining_letters);

		//picking the word
		switch (difficulty)
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
		{
			if (level == selected_level)
			{
				words[i++] = word;
			}
		}


		readFile.close();

		int iRandomNumber = rand() % words_number;

		hidden_word = words[iRandomNumber];


		start_seconds = time(NULL);
		do
		{
			PrintGameState(lives, hidden_word, guessed_letters, difficulty);
			cout << "\n\n";
			PrintAplhabet(remaining_letters, correct_guess);
			// getting letter from user and removing it form Remaining Letters
			bool duplicate_letter;
			char letter;
			do
			{
				letter = GetLetter();
				duplicate_letter = CheckDuplicateLetter(remaining_letters, letter);

			} while (duplicate_letter);

			guessed_letters.push_back(letter);
			remaining_letters.erase(guessed_letters.back());

			//cheking to see if the user guessed a letter if they guessed worng they lose a life 
			bool bCorrectGuess = IsGuessCorrect(guessed_letters, hidden_word);
			if (bCorrectGuess)
			{
				correct_guess.insert(letter);
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
			PrintWinScreen(lives, hidden_word, difficulty, start_seconds);
		}
		else
		{
			PrintGameOverScreen(lives, hidden_word, difficulty, start_seconds);
		}

		//resteting for next game
		remaining_letters.clear();
		correct_guess.clear();
		guessed_letters.clear();
		lives = 7;
		delete[] words;
	} while (true);
}