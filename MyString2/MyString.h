#pragma once
#include <iostream>
using namespace std;

//  MyString class declaration goes here

class myString {
private:
	char *str; //holds the string
public:
	myString();
	myString(const char *s);
	myString(myString &s);
	myString operator=(const myString &s);
	myString operator+(const myString &s);
	bool operator==(const myString &s);
	const char* c_str() const;
	~myString();
};

ostream & operator<<(ostream &o, const myString &s);
