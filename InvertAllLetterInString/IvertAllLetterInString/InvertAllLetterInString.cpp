

#include <iostream>
#include "Read.h"
#include "MyString.h"
using namespace std;

string InvertAllLettersInString(string &Text) {

	for (short i = 0; i < Text.length(); i++) {
		Text[i] = MyString::InvertCharCase(Text[i]);
	}
	return Text;
}

int main()
{
	string Text=Read::ReadString("Please Enter Your String?");

	cout << "\n\nString after inverting all letters case: \n";
	InvertAllLettersInString(Text);
	cout << Text << endl;
}

