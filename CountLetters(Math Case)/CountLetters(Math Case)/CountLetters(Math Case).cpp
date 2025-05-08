

#include <iostream>
#include "Read.h"
#include "MyString.h"
using namespace std;

short CountLetter(string& Text, char& Letter, bool IsCaseSensetive = true) {

	short Count = 0;

	for (short i = 0; i < Text.length(); i++) {
		if (IsCaseSensetive) {
			if (Text[i] == Letter)
				Count++;
		}
		else {
			if (tolower(Text[i]) == tolower(Letter))
				Count++;
		}
	}
	return Count;
}

int main()
{
	string Text=Read::ReadString("Please enter your string?");

	cout << "\n";
	char Letter = Read::ReadChar("Please Enter The Char you want to count ?");

	cout << "\nLetter '" << Letter << "' count = " << CountLetter(Text, Letter);

	cout << "\nLetter '" << Letter << "' or '" << MyString::InvertCharCase(Letter) << "' Count = " << CountLetter(Text, Letter,false);

}


