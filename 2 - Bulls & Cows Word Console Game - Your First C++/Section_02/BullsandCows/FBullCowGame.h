#pragma once
#include<string>

using FString = std::string;
using int32 = int;
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
	bool checkGuessValidity(FString);
	void setCurrentTry(int32);
	//TODO provide a method for counting bulls & coes and increasing turn number

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
