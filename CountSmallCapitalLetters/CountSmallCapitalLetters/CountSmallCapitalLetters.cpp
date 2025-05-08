

#include <iostream>
#include <string>
#include "Read.h"
using namespace std;

enum enWhatToCount
{
	SmallLetters = 0,CapitalLetters=1,DigitLetters=2,PunctLetters=3,AllLetters=4
};

//short CountCapitalLetterInString(string &Text) {
//
//	short Count = 0;
//
//	for (short i = 0; i < Text.length(); i++) {
//		if (isupper(Text[i])) {
//			Count++;
//		}
//	}
//
//	return Count;
//}
//
//short CountSmallLetterInString(string &Text) {
//
//	short Count = 0;
//
//	for (short i = 0;i<Text.length();i++) {
//		if (islower(Text[i])) {
//			Count++;
//		}
//	}
//	return Count;
//}

short CountLettersInString(string &Text,enWhatToCount WhatToCount) {

	short Count = 0;

	if (WhatToCount == AllLetters)
		return Text.length();


	for (short i = 0;i<Text.length();i++){
		if (WhatToCount == SmallLetters && islower(Text[i]))
			Count++;
		else if (WhatToCount == CapitalLetters && isupper(Text[i]))
			Count++;
		else if (WhatToCount == DigitLetters && isdigit(Text[i]))
			Count++;
		else if (WhatToCount == PunctLetters && ispunct(Text[i]))
			Count++;
	}
	return Count;
	
}

int main()
{
	string Text=Read::ReadString("Please Enter Your String?");
	/*cout << "\n\nString length = " << Text.length();

	cout << "\nCapital letters count = " << CountCapitalLetterInString(Text);

	cout << "\nSmall Letters count = " << CountSmallLetterInString(Text) << endl;*/


	cout << "\n\nString length = " <<CountLettersInString(Text,AllLetters)<<endl;
	
	cout << "\nCapital letters count = " << CountLettersInString(Text, CapitalLetters)<<endl;

	cout << "\nSmall Letters count = " << CountLettersInString(Text,SmallLetters) << endl; 

	cout << "\nDigital Letters count = " << CountLettersInString(Text, DigitLetters) << endl;

	cout << "\nPunctuation Letters count = " << CountLettersInString(Text, DigitLetters) << endl;

}


