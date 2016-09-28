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
	this->nMaxIsogramLength_ = 0;
	this->isGameWon_ = false;
	this->isogram_ = "";
	this->myCurrentTry_ = 1;
	this->nMaxIsogramLength_ = 0;
	this->nMaxTries_ = MAX_TRIES;
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

bool FBullCowGame::isIsogram(FString)
{
	return false;
}
