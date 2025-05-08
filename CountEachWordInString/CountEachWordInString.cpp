

#include <iostream>
#include <string>
using namespace std;

string ReadString() {
	string Text;
	getline(cin, Text);
	return Text;
}

short CountEachWordInString(string Text) {
	string delim = " ";
	short Pos,Count=0;
	string Sword;

	while ((Pos=Text.find(delim))!=std::string::npos) {

		Sword = Text.substr(0, Pos);

		if (Sword != "") {
			Count++;
		}

		Text.erase(0, Pos + delim.length());
	}

	if (Text != "") {
		Count++;
	}

	return Count;
}

int main()
{
	cout << "Please Enter your string?\n";

	short Count = CountEachWordInString(ReadString());

	cout << "\nThe number of word in your string is : "<<Count<<endl;
}

