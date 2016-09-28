#include <iostream>
#include <string>
#include <ctype.h>
#include"FBullCowGame.h"

/* This is the console executable qthat makes use of the BullCow class
   This acts as the view in a MVC pattern and is responsible for all user interection.
   For game logic see the FBullCowGame class
 */
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
	printIntro();
	do 
	{
		
		playGame();
		bPlayAgain = askToPlayAgain();
		
	} while (bPlayAgain);
	
	return 0;
}

void printIntro()
{
	// introduce the game
	//constexpr is evaluated at compile time, whereas const might be evaluated at compile time
	constexpr int32 WORLD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORLD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

FText getGuess()
{
	// get a guess from the player
	std::cout << "Enter your guess: ";
	FText guess = "";
	std::getline(std::cin, guess);
	return guess;

}
void playGame()
{
	
	bcGame.reset();
	int32 nMaxTries = bcGame.getnMaxTries();
	FText guess = "";
	//TODO change from FOR to WHILE loop once we validated tries
	for (int32 i = 1; i<= nMaxTries; i++)
	{
		bcGame.setCurrentTry(i);
		std::cout << "Try " << bcGame.getCurrentTry() << ":\n";
		guess = getGuess(); //TODO make guess validation
		// Submit valid guess to the game
		//print number of bulls and cows
		std::cout << "Your guess was: " << guess << std::endl;
	}
	//TODO show a game summary
}
bool askToPlayAgain()
{
	FText response = "";
	std::cout << "Do you want to play again? ";
	std::getline(std::cin, response);
	return (((char)tolower(response[0])) == 'y');

}