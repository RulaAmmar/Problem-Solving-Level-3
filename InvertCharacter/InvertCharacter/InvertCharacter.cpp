

#include <iostream>
#include<string>
#include "Read.h"
using namespace std;

char InvertCharCase(char Letter) {

	return isupper(Letter) ? tolower(Letter) : toupper(Letter);
}

int main()
{
	char Letter=Read::ReadChar("Please Enter a character?");


	cout << "\n\nchar after inverting case: \n";
	Letter=InvertCharCase(Letter);
	cout << Letter << endl;
}

