#include "Dictionary1.h"
#include "WordS.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Dictionary1 Dict;


// validating user inputs
int validate(int input, string message) 
{
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You have entered wrong input" << endl;
			cout << message;
			cin >> input;
		}
		if (!cin.fail())
			return input;
	}
}

int main()
{
	string word, record;
	int noOfTimes;
	char character;

	int task = 0;
	Dict.loadDictionary("dictionary_2022S2.txt");

	while (task != 4) 
	{
		cout << " \n 1 - Find a definition of a word " << endl;
		cout << " 2 - Find words with specific characters " << endl;
		cout << " 3 - List words that have a 'q' without following a 'u' " << endl;
		cout << " 4 - End " << endl << endl;

		cout << "Enter - ";

		cin >> task;

		task = validate(task, "Enter Task - ");

		switch (task) 
		{
		case 1: 
		{
			cout << "Enter word - ";
			cin >> word;
			Dict.findWord(word);
			break;
		}

		case 2: 
		{
			cout << "Enter character - ";
			cin >> character;
			cout << "Enter minimum number of times - ";
			cin >> noOfTimes;
			noOfTimes = validate(noOfTimes, "Enter minimum number of times - ");
			Dict.findCharacter(character, noOfTimes);
			break;
		}

		case 3: 
		{
			Dict.qwithoutu();
			break;
		}
		case 4: 
		{
			cout << "Ending";
			break;
		}

		default: 
		{
			cout << "Unknown Input";
			break;
		}

		}
	}

}

