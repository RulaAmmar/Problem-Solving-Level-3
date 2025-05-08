
#include <iostream>
#include<vector>
using namespace std;

string JoinString(vector<string>& vString,string Delim) {
	string Text="";
	for (string &Value:vString) {
		Text += (Value+Delim);
	}
	return Text.substr(0,Text.length()-Delim.length());
}

string JoinString(string Arr[], short Length, string Delim) {

	string Text = "";

	for (short i = 0; i < Length;i++) {
		Text += (Arr[i] + Delim);
	}

	return Text.substr(0, Text.length() - Delim.length());
}

int main()
{
	//vector<string> vString={ "Rula","Majd","Talia" };

	//cout << JoinString(vString, ",")<<endl;

	string Arr[] = { "Rula","Kisra","Ammar" };

	cout << JoinString(Arr, 3, "+++") << endl;
}


