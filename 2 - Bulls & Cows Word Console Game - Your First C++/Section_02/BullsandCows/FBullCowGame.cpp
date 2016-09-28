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
	constexpr int MAX_TRIES = 8; //constexpr is evaluated at compile time, whereas const mught be evaluated at compile time
	this->nMaxIsogramLength_ = 0;
	this->isGameWon_ = false;
	this->isogram_ = "";
	this->myCurrentTry_ = 1;
	this->nMaxIsogramLength_ = 0;
	this->nMaxTries_ = MAX_TRIES;
	return;
}

//const at the end of method definition means this method cannot member variable values
int FBullCowGame::getnMaxTries() const
{
	return nMaxTries_;

}

void FBullCowGame::setIsogram(std::string)
{
}

std::string FBullCowGame::getIsogram() const
{
	return std::string();
}

void FBullCowGame::setnMaxTries(int nmaxTries)
{
	this->nMaxTries_ = nmaxTries;
	// (*this).nMaxTries_ = maxTries; get the value of this pointer
	return;
}

int FBullCowGame::getIsogramMaxLength() const
{
	return nMaxIsogramLength_;
}

void FBullCowGame::setIsogramMaxLength(int nMaxIsogramLength)
{
	this->nMaxIsogramLength_ = nMaxIsogramLength;
	return;
}

int FBullCowGame::getCurrentTry() const
{
	return myCurrentTry_;
}

bool FBullCowGame::isGameWon() const
{
	return isGameWon_;
}

bool FBullCowGame::checkGuessValidity(std::string)
{
	return false;
}

void FBullCowGame::setCurrentTry(int myCurrentTry)
{
	this->myCurrentTry_ = myCurrentTry;
}

bool FBullCowGame::isIsogram(std::string)
{
	return false;
}
