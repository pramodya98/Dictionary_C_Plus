#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "WordS.h"
using namespace std;

class Dictionary1
{
private:
	vector <Word*> wordVector;

public:
	void loadDictionary(string fileName);
	void findWord(string word);
	void findCharacter(char character, int noOfTimes);
	void qwithoutu();

};

