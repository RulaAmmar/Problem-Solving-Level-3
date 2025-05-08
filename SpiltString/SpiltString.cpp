

#include <iostream>
#include<string>
#include <vector>
using namespace std;

string ReadString() {
	string Text;
	getline(cin, Text);
	return Text;
}

vector<string> SpiltString(string Text,string delim) {
	short pos;
	string sWord;
	vector<string> vWords;

	while ((pos=Text.find(delim))!=std::string::npos) {

		sWord = Text.substr(0, pos);

		if (sWord != "") {
			vWords.push_back(sWord);
		}

		Text.erase(0, pos + delim.length());
	}

	if (Text != "") {
		vWords.push_back(Text);
	}

	return vWords;
}

void PrintVector(vector<string>& vec) {

	for (string &Value:vec) {
		cout << Value << endl;
	}
}

int main()
{
cout << "Please Enter your string?\n";
	
vector<string> vWords=SpiltString(ReadString(),"###");

cout << "Tokens: " << vWords.size() << endl;

PrintVector(vWords);

}

