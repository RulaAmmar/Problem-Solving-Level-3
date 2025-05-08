

#include <iostream>
#include <string>
using namespace std;

string ReadString() {
	string Text;
	getline(cin, Text);
	return Text;
}

void PrintEachWordInString(string Text) {
	string Word="";
	for (short i = 0; i < Text.length(); i++) {
		if (Text[i] != ' ') {
			Word += Text[i];
		}
		else if (Word!="") {
			cout << Word << endl;
			Word = "";
		}
	}

	if (Word != "") {
		cout << Word << endl;
	}

}

int main()
{
	cout << "Please Enter your string\n";

	PrintEachWordInString(ReadString());
}

