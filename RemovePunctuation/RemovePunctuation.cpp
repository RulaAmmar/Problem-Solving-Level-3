

#include <iostream>
#include <string>
using namespace std;

string ReadString(string Message) {

	cout << Message << endl;
	string Text;

	getline(cin, Text);

	return Text;
}

string RemovePunctuations(string& Text) {

	string S1;

	for (short i = 0; i < Text.length(); i++) {
		if (!ispunct(Text[i])) {
			S1 += Text[i];
		}
	}

	return S1;
}

int main()
{
	string Text = ReadString("Please enter your string?");

	cout << "Original String:\n" <<Text;

	cout << "\n\nPauncuations Removed:\n" <<RemovePunctuations(Text);
}

