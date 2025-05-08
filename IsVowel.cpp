
#include <iostream>
using namespace std;

char ReadChar(string Message) {
    char Letter;
    cout << Message << endl;
    cin >> Letter;
    return Letter;
}

//bool IsVowel(char &Letter) {//Soulation not the optimal because using array and forloop
//    char Vowel[] = { 'a','i','o','u','e' };
//
//    for (short i = 0; i < 5;i++) {
//        if (tolower(Letter) == tolower(Vowel[i])) {
//            return true;
//        }
//    }
//    return false;
//}

bool IsVowel(char Letter) {

    Letter = toupper(Letter);
    return ((Letter == 'A' || Letter == 'O' || Letter == 'I' || Letter == 'E' || Letter == 'U'));
}

int main()
{

    char Letter = ReadChar("Please Enter a character?");

    if (IsVowel(Letter) ){
        cout << "\nYes,Letter " << Letter << " is Vowel\n";
    }
    else {
        cout << "\nNo,Letter " << Letter << " is not Vowel\n";
    }
}


