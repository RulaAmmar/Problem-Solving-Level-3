
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
    return ((Letter == 'i') || (Letter == 'o') || (Letter == 'u') || (Letter == 'e') || (Letter == 'a'));
}

short CountVowel(string &Text) {

    short Count = 0;

    for (short i = 0;i<Text.length();i++) {
        if (IsVowel(Text[i]))
            Count++;
    }
    return Count;
}

int main()

{
    cout << "Please enter your string ?" << endl;
    string Text = ReadString();

    cout << "\n\nNumbers of vowel is = " << CountVowel(Text) << endl;
}


