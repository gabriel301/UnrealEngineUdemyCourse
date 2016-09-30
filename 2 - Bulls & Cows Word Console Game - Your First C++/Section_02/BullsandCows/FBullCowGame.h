#pragma once
#include<string>
#include<algorithm>
using FString = std::string;
using int32 = int;

//Enum Class are prefered over plain enums because its labels are "local", ie, you can reuse labels name in other enum classes
enum class EWordStatus 
{
	INVALID_STATUS,
	OK,
	NOT_ISOGRAM,
	WRONG_LENGTH,
	NOT_LOWERCASE
};


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
private:
		//properties/members
		int32 myCurrentTry_;
		int32 nMaxTries_;
		int32 nMaxIsogramLength_;
		FString isogram_;
		bool bIsGameWon_;
		//methods
		bool isIsogram_(FString);
			
};
