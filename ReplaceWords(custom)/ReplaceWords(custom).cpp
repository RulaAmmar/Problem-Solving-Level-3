

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString(string Message) {

	string Text;
	cout << Message << endl;

	getline(cin, Text);

	return Text;

}

vector<string> SplitString(string& Text, string Delim) {

	short Pos;
	string sWord;
	vector<string> vString;

	while((Pos=Text.find(Delim) )!= std::string::npos) {
		sWord = Text.substr(0, Pos);
		if (sWord != "") {
			vString.push_back(sWord);
		}
		Text.erase(0, Pos + Delim.length());
	}
	if (Text != "") {
		vString.push_back(Text);
	}
	return vString;
}

string JoinString(vector<string> &vString,string Delim) {

	string Text;

	for (string &sWord:vString) {
		Text += (sWord + Delim);
	}

	return Text.substr(0, Text.length() - Delim.length());
}

string LowerAllString(string& Text) {
	for (short i = 0;i<Text.length();i++) {
		Text[i] = tolower(Text[i]);
	}

	return Text;
}

string ReplaceWordsInStringUsingSplit(string &OriginalString,string &StringToReplace
	,string &StringReplaceTo,bool MatchCase=false) {

	vector<string> vString = SplitString(OriginalString, " ");

	for (string &sWord : vString) {

		if (MatchCase) {
			if (sWord == StringToReplace) {
				sWord = StringReplaceTo;
			}
		}
		else {
			
			if (LowerAllString(sWord)==LowerAllString(StringToReplace)) {
				sWord = StringReplaceTo;
			}
		}
		
	}

	return JoinString(vString, " ");
}

int main()
{
	string OriginalString =ReadString("Please enter your string ?");

	string StringToReplace = ReadString("\nPlease enter the word to be replaced ?");

	string StringReplaceTo = ReadString("\nPlease enter the new word ?");

	cout << "\nOriginal string :\n";
	cout << OriginalString<<endl;

	cout << "\nString after replace words\n";
	cout << ReplaceWordsInStringUsingSplit(OriginalString, StringToReplace, StringReplaceTo);
}


