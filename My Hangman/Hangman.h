#pragma once
#include "Game.h"


class Hangman
{
private:
	//collection used 
	vector<char> guessed_letters;
	set<char> correct_guess;
	set<char> remaining_letters;

	string level, word;             // readed data
	string selected_level;
	unsigned int words_number;

	//testing word 
	string hidden_word;

	// set up variables 
	int lives;
	bool has_player_won;
public:
	Hangman();
	void GameLoop();
};

