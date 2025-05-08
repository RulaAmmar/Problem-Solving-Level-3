

#include <iostream>
#include <iostream>
#include<string>
using namespace std;

string ReadString(string Message) {

	string Text;
	cout << Message << endl;

	getline(cin, Text);

	return Text;
}

string ReplaceWordsInStringUsingBuiltInFunction(string &OriginalString,string &StringToReplce,string &ReplaceTo) {

	short Pos = OriginalString.find(StringToReplce);//0
	while (Pos!=std::string::npos) {
		OriginalString=OriginalString.replace(Pos, StringToReplce.length(), ReplaceTo);

		Pos=OriginalString.find(StringToReplce);

	}

	return OriginalString;
}

int main()
{
  
	string OriginalString, sToReplace, sReplaceTo;

	OriginalString = ReadString("Please Enter Your string ?");

	sToReplace = ReadString("Please enter the word is to replace ?");

	sReplaceTo = ReadString("Please enter the new word ?");

	cout << "\nOriginal String\n" << OriginalString;

	cout << "\n\nstring after replace\n";

  cout<< ReplaceWordsInStringUsingBuiltInFunction(OriginalString, sToReplace, sReplaceTo);
}

