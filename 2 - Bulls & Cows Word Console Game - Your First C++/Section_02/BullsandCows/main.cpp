#include <iostream>
#include <string>
#include <ctype.h>
#include"FBullCowGame.h"

/* This is the console executable qthat makes use of the BullCow class
   This acts as the view in a MVC pattern and is responsible for all user interection.
   For game logic see the FBullCowGame class
 */
//Creating alias for types, exaclty the same effect of typedef (C style)
using FText = std::string;
using int32 = int;
//Function prototypes
void printIntro();
FText getGuess();
void playGame();
bool askToPlayAgain();

FBullCowGame bcGame; //instantiate a new game (object on the stack)
//FBullCowGame *bcGame = new FBullCowGame(); //instantiate a new game (object on the heap (dynamic allocation)
//The entry point for our app
int main()
{
	bool bPlayAgain = false;
	do 
	{
		printIntro();
		playGame();
		bPlayAgain = askToPlayAgain();
		
	} while (bPlayAgain);
	
	return 0;
}

void printIntro()
{
	// introduce the game
	//constexpr is evaluated at compile time, whereas const might be evaluated at compile time
	//constexpr int32 WORLD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << bcGame.getIsogramLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

FText getValidGuess()
{
	FText guess = "";
	EWordStatus status = EWordStatus::INVALID_STATUS;
	// get a valid guess from the player
	do
	{
		std::cout << "Enter your guess: ";
		std::getline(std::cin, guess);
		status = bcGame.checkGuessValidity(guess);
		switch (status)
		{
			case EWordStatus::NOT_ISOGRAM:
				std::cout << "Please enter an isogram word!\n";
				break;
			case EWordStatus::WRONG_LENGTH:
				std::cout << "Please enter a " << bcGame.getIsogramLength() << " letter word!\n";
				break;
			case EWordStatus::NOT_LOWERCASE:
				std::cout << "Please enter a lowercase word!\n";
				break;
		}
	} while (status != EWordStatus::OK);
	
	return guess;

}
void playGame()
{
	
	bcGame.reset();
	int32 nMaxTries = bcGame.getnMaxTries();
	FText guess = "";
	
	while((!bcGame.isGameWon()) && (bcGame.getCurrentTry() <= nMaxTries))
	{
		//bcGame.setCurrentTry(i);
		std::cout << "Try " << bcGame.getCurrentTry() << " of "<<bcGame.getnMaxTries()<<"\n";
		std::cout << "Enter you guess: ";
		
		guess = getValidGuess();
		// Submit valid guess to the game
		FBullCowCount nBullsCows = bcGame.submitValidGuess(guess);
		//print number of bulls and cows

		std::cout <<"Bulls: " << nBullsCows.bulls << std::endl;
		std::cout << "Cows: " << nBullsCows.cows << std::endl;
	}
	//TODO show a game summary
	bcGame.PrintGameSummary();
	return;
}
bool askToPlayAgain()
{
	FText response = "";
	std::cout << "Do you want to play again? ";
	std::getline(std::cin, response);
	return (((char)tolower(response[0])) == 'y');

}