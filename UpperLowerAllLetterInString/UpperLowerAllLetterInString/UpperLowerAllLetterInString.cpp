

#include <iostream>
#include<string>
using namespace std;

string ReadText(string Message) {
	string Text;
	cout << Message << endl;
	getline(cin, Text);
	return Text;
}

string UpperAllLetterInString(string Text) {
	for (short i = 0; i < Text.length();i++) {
		Text[i] = toupper(Text[i]);
	}
	return Text;
}

string LowerAllLetterInString(string Text) {
	for (short i = 0;i<Text.length();i++) {
		Text[i] = tolower(Text[i]);
	}
	return Text;
}

int main()
{
	string Text = ReadText("Please enter your string?");

	Text = UpperAllLetterInString(Text);
	cout << "Upper All Letter In String: " << Text << endl;

	Text = LowerAllLetterInString(Text);
	cout << "\nLower All Letter In String : " << Text << endl;


}

