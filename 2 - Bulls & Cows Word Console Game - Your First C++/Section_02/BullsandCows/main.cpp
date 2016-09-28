#include <iostream>
#include <string>
#include <ctype.h>
#include"FBullCowGame.h"


//Function prototypes
void printIntro();
std::string getGuess();
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
	constexpr int WORLD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORLD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

std::string getGuess()
{
	// get a guess from the player
	std::cout << "Enter your guess: ";
	std::string guess = "";
	std::getline(std::cin, guess);
	return guess;

}
void playGame()
{
	
	bcGame.reset();
	int nMaxTries = bcGame.getnMaxTries();
	std::string guess = "";
	//TODO change from FOR to WHILE loop once we validated tries
	for (int i = 1; i<= nMaxTries; i++)
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
	std::string response = "";
	std::cout << "Do you want to play again? ";
	std::getline(std::cin, response);
	return (((char)tolower(response[0])) == 'y');

}