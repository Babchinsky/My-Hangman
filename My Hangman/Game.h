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

class Game
{
private:
	vector<char> vGuessedLetters;
	set<char> sCorrectGuess;
	set<char> sRemainingLetters;

	//testing word 
	string HiddenWord;

	// set up variables 
	int iLives = 7;
	bool bHasPlayerWon = false;
public:
	Game()
	{

	}
};


void PrintHangMan(int iLives);



void PrintHangMan(int iLives, int iColor);

char Intro();
set<char> FillAlphabet(set<char> sAlphabet);
void PrintAplhabet(set<char> sAlphabet, set<char> sCorretGuess);
char GetLetter();
bool CheckDuplicateLetter(set<char> sListOfLetters, char cletter);
bool IsGuessCorrect(vector<char> vGuess, string word);
void PrintWord(string sWord, vector<char> vPLayerGuss);
void PrintGameState(int iLives, string sWord, vector<char> vPLayerGuss);

void PrintGameOverScreen(int iLives, string sWord);
void PrintWinScreen(int iLives, string sWord);
bool CheckIfPlayerHasWon(string sWord, set <char> sCorrectGuesses);

void ChangeTextColour(int iColorValue);
void ChangeConsoleWindowSize(int iXValue, int iYvalue);

void PrintGameOverScreen(int iLives, string sWord);
void PrintWinScreen(int iLives, string sWord);
bool CheckIfPlayerHasWon(string sWord, set <char> sCorrectGuesses);
void ChangeTextColour(int iColorValue);
void ChangeConsoleWindowSize(int iXValue, int iYvalue);

