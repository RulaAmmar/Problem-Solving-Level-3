

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

const string ClientsFileName = "ClientsFile.txt";

struct strClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

vector<string> SplitString(string Text, string Seperator = "#//#") {

    short Pos;
    string sWord;
    vector<string> vString;

    while ((Pos = Text.find(Seperator)) != std::string::npos) {

        sWord = Text.substr(0, Pos);
        if (sWord != "") {
            vString.push_back(sWord);
            Text.erase(0, Pos + Seperator.length());
        }
    }

    if (Text != "") {
        vString.push_back(Text);
    }

    return vString;
}

strClient ConvertDataLineToRecord(string& DataLine, string Seperator = "#//#") {

    vector<string> vString = SplitString(DataLine, Seperator);

    strClient Client;

    Client.AccountNumber = vString.at(0);
    Client.PinCode = vString.at(1);
    Client.Name = vString.at(2);
    Client.Phone = vString.at(3);
    Client.AccountBalance = stod(vString.at(4));

    return Client;
}

vector<strClient> LoadClientsDataFromFileToVector(const string& FileName) {

    fstream ClientsFile;
    string Line;

    vector<strClient> vClients;
    strClient Client;

    ClientsFile.open(FileName, ios::in);

    if (ClientsFile.is_open()) {
        while (getline(ClientsFile, Line)) {
            Client = ConvertDataLineToRecord(Line);
            vClients.push_back(Client);
        }
    }
    else {
        cout << "\nThere is a problem with the file, it was not read\n";
    }

    return vClients;
}

void PrintClientData(strClient& Client) {
    cout << "\nThe Following are the client details : \n\n";
    cout << "Account Number : " << Client.AccountNumber << endl;
    cout << "Pin Code : " << Client.PinCode << endl;
    cout << "Name : " << Client.Name << endl;
    cout << "Phone : " << Client.Phone << endl;
    cout << "Account Balance : " << Client.AccountBalance << endl;
}

 bool FindClientByAccountNumber(string &AccountNumber,strClient &Client) {

     vector<strClient> vClients = LoadClientsDataFromFileToVector(ClientsFileName);

    for (strClient &C : vClients) {
        if (C.AccountNumber == AccountNumber) {
            Client = C;
            return true;
       }
    }

    return false;
}

 string ReadClientAccountNumber() {

     string AccountNumber;

     cout << "Please Enter Account Number ?\n";

     cin >> AccountNumber;
     return AccountNumber;
 }

int main()
{

 strClient Client;
 string AccountNumber = ReadClientAccountNumber();

 if (FindClientByAccountNumber(AccountNumber, Client)) {
     PrintClientData(Client);
 }
 else {
     cout << "Client With Account Number (" << AccountNumber << ") Not Found !\n";
 }
}

