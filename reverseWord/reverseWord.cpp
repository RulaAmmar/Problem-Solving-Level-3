

#include <iostream>
#include<string>
#include<vector>
using namespace std;
string ReadString()
{
	string S1;
	cout << "Please Enter Your String?\n";
	getline(cin, S1);
	return S1;
}

vector<string> SplitString(string& Text, string Delim) {

	vector<string> vString;
	string sWord;
	short Pos;

	while ((Pos=Text.find(Delim) )!= std::string::npos) {
		sWord = Text.substr(0, Pos);

		if (sWord != "") {
			vString.push_back(sWord);
		}

		Text.erase(0,Pos+Delim.length());
	}

	if (Text != "") {
		vString.push_back(Text);
	}

	return vString;
}

string ReverseWordInString(string &Text) {

	vector<string>::iterator iter;

	string ReverseString = "";

	vector<string> vString = SplitString(Text,"##$$");

	iter = vString.end();

	while (iter != vString.begin()) {
		iter--;
		ReverseString += *iter + "##$$";
	}

	return ReverseString.erase(ReverseString.length() - 4, 4);
	
}

int main()
{
	string Text = ReadString();

	cout<<endl<<ReverseWordInString(Text)<<endl;
}
