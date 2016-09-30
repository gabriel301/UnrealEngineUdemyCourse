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
	this->bIsGameWon_ = false;
	this->isogram_ = "";
	this->myCurrentTry_ = 1;
	this->nMaxIsogramLength_ = 0;
	this->nMaxTries_ = MAX_TRIES;
	this->isogram_ = HIDDEN_WORD;
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
	return this->bIsGameWon_;
}

EWordStatus FBullCowGame::checkGuessValidity(FString guess) 
{
	FString guessLower = guess;

	//converts guess to lowercasee
	std::transform(guess.begin(), guess.end(), guessLower.begin(), ::tolower);

	if (!(this->isIsogram_(guess)))
	{
		return EWordStatus::NOT_ISOGRAM;
	}
	else if (strcmp(guess.c_str(),guessLower.c_str())!=0)
	{
		return EWordStatus::NOT_LOWERCASE;
	}
	else if (this->getIsogramLength() != guess.length())
	{		
		return EWordStatus::WRONG_LENGTH;
	}
	else
	{
		return EWordStatus::OK; //TODO MAKE ACTUAL ERROR
	}
	
}

void FBullCowGame::setCurrentTry(int32 myCurrentTry)
{
	this->myCurrentTry_ = myCurrentTry;
}

int32 FBullCowGame::getIsogramLength() const
{
	return this->isogram_.length();
}

//Receives a valid guess, increments turn and returns count
FBullCowCount FBullCowGame::submitValidGuess(FString guess)
{
	this->setCurrentTry(this->getCurrentTry() + 1);

	FBullCowCount bullCowCount;
	int nIsogramLength = this->getIsogramLength();

	//Assuming Guess and Hidden Word has the same length
	for (int32 isogramIndex = 0; isogramIndex<nIsogramLength; isogramIndex++)
	{
		for (int32 guessIndex = 0; guessIndex<nIsogramLength; guessIndex++)
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
	//Game is won if bulls count is equals the Hidden Word Length
	this->bIsGameWon_ = (bullCowCount.bulls == nIsogramLength);
	return bullCowCount;
}

bool FBullCowGame::isIsogram_(FString word)
{
	
	for (int i = 0; i < word.length(); i++)
	{
		int first = word.find(word[i]);
		int last = word.rfind(word[i]);
		//if one letter appears in 2 different positions at the string, means it is repeated and then the word is not an isogram
		if (first != last)
		{
			return false;
		}
				
	}
	return true;
}


