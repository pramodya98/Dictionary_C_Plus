#include "WordS.h"
#include <iostream>

using namespace std;

Word::Word(string name, string definition, string type) 
{
	this->name = name;
	this->definition = definition;
	this->type = type;
}
string Word::getName() 
{
	return name;
}
string Word::getdefinition() 
{
	return definition;
}
string Word::getType() 
{
	return type;
}

void Word::printdefinition() 
{
	cout << name << " " << printType() << " " << definition << endl;
}

//word type into formatted way
string Word::printType() 
{
	if (type == "noun")
	{
		return "(noun.)";
	}
	else if (type == "verb")
	{
		return "(verb.)";
	}
	else if (type == "adverb")
	{
		return"(adverb.)";
	}
	else if (type == "adjective")
	{
		return"(adjective.)";
	}
	else if (type == "preposition")
	{
		return"(preposition.)";
	}
	else if (type == "miscellaneous")
	{
		return"(miscellaneous.)";
	}
	else if (type == "proper_noun")
	{
		return"(proper_noun.)";
	}
	else if (type == "noun_and_verb")
	{
		return"(noun.verb.)";
	}
	else
	{
		return "(" + type + ".)";
	}



}