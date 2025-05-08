

#include <iostream>
#include "Read.h"
using namespace std;

short CountCharacterInString(string& Text, char& Letter) {

    short Count = 0;

    for (short i = 0; i < Text.length(); i++) {
        if (Text[i] == Letter) {
            Count++;
        }
    }
    return Count;
}

int main()
{
    string Text = Read::ReadString("Please Enter Your String?");
    cout << "\n";
    char Letter = Read::ReadChar("Pleae Enter The Letter you want to count ?");

    cout << "\nLetter " << Letter << " Count = " << CountCharacterInString(Text, Letter)<<endl;
}


