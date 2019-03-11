// member function implementations go in this file
#include <iostream>
#include "MyString.h"
#include <cstring>

using namespace std;

//default constructor
//no parameters
//no return type
myString::myString()
{
	str = nullptr;
}

//initialisation constructor
//parameters: const char *s
//no return type
myString::myString(const char *s)
{
	str = new char[strlen(s) + 1];
	strcpy_s(str, strlen(s) + 1, s);
}

//copy constructor
//parameters: const char *s
//no return type
myString::myString(myString &s)
{
	str = new char[strlen(s.str) + 1];
	strcpy_s(str, strlen(s.str) + 1, s.str);
}

//overloaded = operator
//parameters: const myString &s
//returns pointer to this
myString myString::operator=(const myString &s)
{
	if (this != &s)
	{
		delete[] str;
		str = new char[strlen(s.str) + 1];
		strcpy_s(str, strlen(s.str) + 1, s.str);
	}

	return *this;
}

//overloaded + operator
//parameters: const myString &s
//returns myString
myString myString::operator+(const myString &s)
{
	myString newString;
	delete[] newString.str;
	int size = strlen(str) + strlen(s.str) + 2;
	newString.str = new char[size];
	strcpy_s(newString.str, size, str);
	strcat_s(newString.str, size, " ");
	strcat_s(newString.str, size, s.str);
	return newString;
}

//overloaded == operator
//parameters: const myString &s
//returns bool value
bool myString::operator==(const myString &s)
{
	bool status = true;
	if (strlen(str) == strlen(s.str))
	{
		for (int i = 0; i < strlen(s.str) && status; i++)
		{
			if (str[i] == s.str[i])
			{
				status = true;
			}
			else
			{
				status = false;
			}
		}
	}
	return status;
}

//const char
//no parameters
//returns character array
const char* myString::c_str() const
{
	return str;
}

//destructor
//no parameters
//no return type
myString::~myString()
{
	delete[] str;
}
