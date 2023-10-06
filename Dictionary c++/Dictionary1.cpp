#include "Dictionary1.h"
#include "WordS.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


void Dictionary1::loadDictionary(string fileName)
{

	string word;
	string type;
	string definition;
	string linebreak;

	Word* wordObject;
	ifstream myFile(fileName);


	while (!myFile.eof())
	{
		getline(myFile, type);
		getline(myFile, word);
		getline(myFile, definition);
		wordObject = new Word(word, definition, type);

		wordVector.push_back(wordObject);

		getline(myFile, linebreak);

	}

	// Close the file
	myFile.close();

}

//searching the vector
void Dictionary1::findWord(string word)
{
	auto wordIterator = find_if(wordVector.begin(), wordVector.end(), [&word](Word* object) {return object->getName() == word; });

	if (wordIterator != wordVector.end()) 
	{
		(*wordIterator)->printdefinition();
		return;
	}

	std::cout << "Word not found" << endl;
}

//geting a character and no of times from the user and searches
void Dictionary1::findCharacter(char character, int noOfTimes)
{
	int count;
	string wordName;
	for (Word* wordObject : wordVector)
	{
		wordName = wordObject->getName();

		count = std::count(wordName.begin(), wordName.end(), character);

		if (count > noOfTimes) 
		{
			wordObject->printdefinition();
		}


	}

}

//print words having q without u 
void Dictionary1::qwithoutu()
{
	string wordName;
	for (Word* wordObject : wordVector)
	{
		wordName = wordObject->getName();
		for (int i = 0; i < wordName.length(); i++) 
		{
			if ((wordName[i] == 'q' && i + 1 < wordName.length() && wordName[i + 1] != 'u') || (wordName[i] == 'q' && i + 1 >= wordName.length())) 
			{
				wordObject->printdefinition();
				break;
			}
		}
	}

}
