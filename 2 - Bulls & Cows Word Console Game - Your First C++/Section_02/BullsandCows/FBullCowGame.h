#pragma once
#include<string>
#include<algorithm>
#include<iostream>
#include <map>

#define TMap std::map

using FString = std::string;
using int32 = int;

//Enum Class are preferred over plain enums because its labels are "local", ie, you can reuse labels name in other enum classes
/*
	Enum Class designed to store the word status in order to check the word validity
*/
enum class EWordStatus 
{
	INVALID_STATUS,
	OK,
	NOT_ISOGRAM,
	WRONG_LENGTH,
	NOT_LOWERCASE
};


/*
	Struct designed to store the count of bulls and cows os the current turn
*/
struct FBullCowCount
{
	int32 bulls = 0;
	int32 cows = 0;
};



/*
	Class designed to manage all game logic and store the current state of the game
*/
class FBullCowGame 
{
public:
	//properties

	//methods
	FBullCowGame(); //constructor
	~FBullCowGame(); //destructor
	void reset(); 
	int32  getnMaxTries() const; //const at the end of method definition means this method cannot change member variables
	void setIsogram(FString);
	FString getIsogram() const;
	void setnMaxTries(int32);
	int32  getIsogramMaxLength() const;
	void setIsogramMaxLength(int32);
	int32 getCurrentTry() const;
	bool isGameWon() const;
	EWordStatus checkGuessValidity(FString);
	void setCurrentTry(int32);
	int32 getIsogramLength() const;
	//counts bulls and cows and increases try number assuming a valid guess
	FBullCowCount submitValidGuess(FString);
	void printGameSummary() const;
private:
		//properties/members
		int32 myCurrentTry_;
		int32 nMaxTries_;
		int32 nMaxIsogramLength_;
		FString isogram_;
		bool bIsGameWon_;
		//methods
		bool isIsogram_(FString);
		bool isLowerCase_(FString);
			
};
