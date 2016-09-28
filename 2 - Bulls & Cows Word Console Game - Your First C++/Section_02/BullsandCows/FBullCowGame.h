#pragma once
#include<string>
class FBullCowGame 
{
public:
	//properties

	//methods
	FBullCowGame(); //constructor
	~FBullCowGame(); //destructor
	void reset(); //TODO make a more rich return value
	int  getnMaxTries() const; //const at the end of method definition means this method cannot change member variables
	void setIsogram(std::string);
	std::string getIsogram() const;
	void setnMaxTries(int);
	int  getIsogramMaxLength() const;
	void setIsogramMaxLength(int);
	int getCurrentTry() const;
	bool isGameWon() const;
	bool checkGuessValidity(std::string);
	void setCurrentTry(int);
	//TODO provide a method for counting bulls & coes and increasing turn number

private:
		//properties/members
		int myCurrentTry_;
		int nMaxTries_;
		int nMaxIsogramLength_;
		std::string isogram_;
		bool isGameWon_;
		//methods
		bool isIsogram(std::string);
			
};
