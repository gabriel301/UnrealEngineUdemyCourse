#pragma once
#include<string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 bulls = 0;
	int32 cows = 0;
};

class FBullCowGame 
{
public:
	//properties

	//methods
	FBullCowGame(); //constructor
	~FBullCowGame(); //destructor
	void reset(); //TODO make a more rich return value
	int32  getnMaxTries() const; //const at the end of method definition means this method cannot change member variables
	void setIsogram(FString);
	FString getIsogram() const;
	void setnMaxTries(int32);
	int32  getIsogramMaxLength() const;
	void setIsogramMaxLength(int32);
	int32 getCurrentTry() const;
	bool isGameWon() const;
	bool checkGuessValidity(FString) const;
	void setCurrentTry(int32);
	int32 getIsogramLength() const;
	//counts bulls and cows and increases try number assuming a valid guess
	FBullCowCount submitGuess(FString);
private:
		//properties/members
		int32 myCurrentTry_;
		int32 nMaxTries_;
		int32 nMaxIsogramLength_;
		FString isogram_;
		bool isGameWon_;
		//methods
		bool isIsogram(FString);
			
};
