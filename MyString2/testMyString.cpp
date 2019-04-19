// main goes in this file
#include <iostream>
#include "MyString.h"
using namespace std;

//overloaded << operator 
//parameters: const myString &s
//returns ostream item
ostream& operator<<(ostream &o, const myString &s)
{
	o << s.c_str();
	return o;
}

int main()
{
	myString s1("Napoleon"); //test string
	myString s2; //second test string
	s2 = s1;
	cout << "S1: " << s1 << " S2: " << s2 << endl;

	myString s3 = s1; //third test string

	s1 = s2 = s3;

	s1 = s1;

	myString s4("Bonaparte"); //fourth test string
	cout << "S3 + S4: ";
	cout << s3 + s4 << endl;

	if (s3 == s2)
	{
		cout << "Equal strings\n";
	}
	else
		cout << "Not equal\n";

	return 0;
}