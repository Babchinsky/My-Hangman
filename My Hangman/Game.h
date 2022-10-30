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
char Intro();
set<char> FillAlphabet(set<char> sAlphabet);
void PrintAplhabet(set<char> sAlphabet, set<char> sCorretGuess);
char GetLetter();
bool CheckDuplicateLetter(set<char> sListOfLetters, char cletter);
bool IsGuessCorrect(vector<char> vGuess, string word);
void PrintWord(string sWord, vector<char> vPLayerGuss);
void PrintGameState(int iLives, string sWord, vector<char> vPLayerGuss);
void PrintGameOverScreen(int iLives);
void PrintWinScreen(int iLives, string sWord);
bool CheckIfPlayerHasWon(string sWord, set <char> sCorrectGuesses);

void ChangeTextColour(int iColorValue);
void ChangeConsoleWindowSize(int iXValue, int iYvalue);