
#include <iostream>
#include <string>
using namespace std;

string ReadString() {
	string Text;
	getline(cin, Text);
	return Text;
}

bool IsVowel(char Letter) {
	Letter = tolower(Letter);
	return(Letter == 'i' || Letter == 'o' || Letter == 'u' || Letter == 'e' || Letter == 'a');
}

void PrintAllVowelsInString(string& Text) {

	for (short i = 0; i < Text.length(); i++) {
		if (IsVowel(Text[i])) {
			cout << Text[i] << " ";
		}
	}
}

int main()
{
	cout << "Please Enter Your String ?\n";
    string Text=ReadString();

	PrintAllVowelsInString(Text);
}


