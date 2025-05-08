

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct strClientData
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

string ReadString(string Message) {

    string Text;

    cout << Message << endl;

    getline(cin, Text);

    return Text;
}

vector<string> SplitString(string &Text,string Seperator) {

    short Pos;
    string sWord;
    vector<string> vString;

    while ((Pos=Text.find(Seperator))!=std::string::npos) {

        sWord = Text.substr(0, Pos);
        if (sWord != "") {
            vString.push_back(sWord);
        }
        Text.erase(0, Pos + Seperator.length());
    }

    if (Text != "") {
        vString.push_back(Text);
    }

    return vString;
}

strClientData ConvertLineDataToRecord(string &LineData,string Seperator) {

    vector<string> vString = SplitString(LineData, Seperator);

    strClientData ClientData;

    ClientData.AccountNumber = vString.at(0);
    ClientData.PinCode = vString.at(1);
    ClientData.Name = vString.at(2);
    ClientData.Phone = vString.at(3);
    ClientData.AccountBalance = stod(vString.at(4));

    return ClientData;
}

void PrintClientRecord(strClientData &ClientData) {

    cout << "Account Number : " << ClientData.AccountNumber << endl;
    cout << "Pin Code : " << ClientData.PinCode << endl;
    cout << "Name : " << ClientData.Name << endl;
    cout << "Phone : " << ClientData.Phone << endl;
    cout << "Account Balance : " << ClientData.AccountBalance << endl;

}


int main()
{
    string LineRecord=ReadString("Line Record is : \n");

    cout << "\nThe following is the extracted client Record : \n\n";

    strClientData ClientData = ConvertLineDataToRecord(LineRecord, "#//#");

    PrintClientRecord(ClientData);
    
}


