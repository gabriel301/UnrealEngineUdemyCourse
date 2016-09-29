#include "FBullCowGame.h"
FBullCowGame::FBullCowGame()
{
	this->reset();
}

FBullCowGame::~FBullCowGame()
{
}

void FBullCowGame::reset()
{
	constexpr int32 MAX_TRIES = 8; //constexpr is evaluated at compile time, whereas const mught be evaluated at compile time
	const FString HIDDEN_WORD = "planet";
	this->nMaxIsogramLength_ = 0;
	this->isGameWon_ = false;
	this->isogram_ = "";
	this->myCurrentTry_ = 1;
	this->nMaxIsogramLength_ = 0;
	this->nMaxTries_ = MAX_TRIES;
	this->isogram_ = HIDDEN_WORD;
	this->nIsogramLength_ = (int32)this->isogram_.length();
	return;
}

//const at the end of method definition means this method cannot member variable values
int32 FBullCowGame::getnMaxTries() const
{
	return nMaxTries_;

}

void FBullCowGame::setIsogram(FString)
{
}

FString FBullCowGame::getIsogram() const
{
	return FString();
}

void FBullCowGame::setnMaxTries(int32 nmaxTries)
{
	this->nMaxTries_ = nmaxTries;
	// (*this).nMaxTries_ = maxTries; get the value of this pointer
	return;
}

int32 FBullCowGame::getIsogramMaxLength() const
{
	return nMaxIsogramLength_;
}

void FBullCowGame::setIsogramMaxLength(int32 nMaxIsogramLength)
{
	this->nMaxIsogramLength_ = nMaxIsogramLength;
	return;
}

int32 FBullCowGame::getCurrentTry() const
{
	return myCurrentTry_;
}

bool FBullCowGame::isGameWon() const
{
	return isGameWon_;
}

bool FBullCowGame::checkGuessValidity(FString)
{
	return false;
}

void FBullCowGame::setCurrentTry(int32 myCurrentTry)
{
	this->myCurrentTry_ = myCurrentTry;
}

//Receives a valid guess, increments turn and returns count
FBullCowCount FBullCowGame::submitGuess(FString guess)
{
	//increments the turn number
	this->setCurrentTry(this->getCurrentTry() + 1);
	//setup a return variable
	FBullCowCount bullCowCount;

	for (int32 isogramIndex = 0; isogramIndex<this->nIsogramLength_; isogramIndex++)
	{
		for (int32 guessIndex = 0; guessIndex<this->nIsogramLength_; guessIndex++)
		{
			if (guess[guessIndex] == this->isogram_[isogramIndex])
			{
				if (guessIndex == isogramIndex)
					bullCowCount.bulls++;
				else
					bullCowCount.cows++;
			}
		}
	}
	return bullCowCount;
}

bool FBullCowGame::isIsogram(FString)
{
	return false;
}
