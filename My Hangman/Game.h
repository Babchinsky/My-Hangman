#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <conio.h>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <Windows.h>
#include <ctime>

using namespace std;

enum MyEnum
{
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	AQUA = 3,
	RED = 4,
	PURPLE = 5,
	YELLOW = 6,
	WHITE = 7,
};

void PrintHangMan(int lives, int color);
char Intro();
set<char> FillAlphabet(set<char> alphabet);
void PrintAplhabet(set<char> alphabet, set<char> correct_guess);
char GetLetter();
bool CheckDuplicateLetter(set<char> list_of_letters, char cletter);
bool IsGuessCorrect(vector<char> guess, string word);
void PrintWord(string word, vector<char> player_guess);
void PrintGameState(int lives, string word, vector<char> player_guess);
void PrintGameOverScreen(int lives, string word);
void PrintWinScreen(int lives, string word);
bool CheckIfPlayerHasWon(string word, set <char> correct_guesses);

void ChangeTextColor(int color_value);
void ChangeConsoleWindowSize(int x_value, int y_value);

