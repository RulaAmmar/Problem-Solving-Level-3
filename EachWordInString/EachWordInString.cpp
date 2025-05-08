

#include <iostream>
#include<string>
using namespace std;

string ReadString() {
	string Text;
	getline(cin, Text);
	return Text;
}

void PrintEachWordInString(string Text) {
	short Pos;
	string delim = " ";
	string sWord;

	while (Pos=Text.find(delim)!=std::string::npos) {

		sWord = Text.substr(0, Pos);

		if (sWord != "") {
			cout << sWord << endl;
		}

		Text.erase(0, Pos + delim.length());
	}

	if (Text != "") {
		cout << Text << endl;
	}
}

int main()
{
	cout << "Please Enter Your String?\n";

	PrintEachWordInString(ReadString());
}


