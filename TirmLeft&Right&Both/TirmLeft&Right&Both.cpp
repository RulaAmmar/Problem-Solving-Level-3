

#include <iostream>
#include<string>
#include<string>
using namespace std;

string ReadString() {
    string Text;
    getline(cin, Text);
    return Text;
}

string TrimLeft( string &Text) {
    for (short i = 0; i < Text.length(); i++) {
        if (Text[i] != ' ') {
           return Text.substr(i);
       
        }
       
    }
    return "";
}

string TrimRight( string Text) {
    for (short i = Text.length() - 1; i >= 0; i--) {
        if (Text[i] != ' ') {
            return Text.substr(0, i + 1);
        }
    }
    return "";
}

string TrimBoth(string Text) {
  
    return TrimRight(TrimLeft(Text));
}

int main()
{
    /*cout << "Please Enter your string?\n";

   string Text =ReadString();

    cout << "Text Length before Trim Right " << Text.length() << endl;*/

    cout<< TrimLeft(ReadString());

    cout << Text<<endl;

    //cout <<"Text Length after Trim Right "<< Text.length()<<endl;

    /*cout << "Text Length before Trim Left " << Text.length() << endl;

    Text = TrimLeft(Text);

    cout << Text << endl;

    cout << "Text Length after Trim Left " << Text.length() << endl;*/

   // cout << "Text Length before Trim Left and right " << Text.length() << endl;

   // cout<< TrimBoth(ReadString())<<endl;

    //cout << Text << endl;

   // cout << "Text Length after Trim Left and right " << Text.length() << endl;
}


