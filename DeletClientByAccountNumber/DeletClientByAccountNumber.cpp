
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

string ReadClientAccountNumber() {

    string AccountNumber;

    cout << "Please Enter Account Number ?\n";

    cin >> AccountNumber;
    return AccountNumber;
}

bool FindClientIndexByAccountNumber(string& AccountNumber,vector<strClient> &vClients,short &Index) {

    for (short i = 0; i < vClients.size(); i++) {

        if (vClients.at(i).AccountNumber == AccountNumber) {
            Index = i;
            return true;
        }
    }

    return false;
}

bool ConfirmDelete() {

    char Sure;

    cout << "\nAre you sure you want delete this client y/n?";

    cin >> Sure;

    return tolower(Sure) == 'y';

}

string ConvertRecordToLine(strClient& ClientData, string Seperator = "#//#") {

    string ClientRecord;

    ClientRecord += ClientData.AccountNumber + Seperator;
    ClientRecord += ClientData.PinCode + Seperator;
    ClientRecord += ClientData.Name + Seperator;
    ClientRecord += ClientData.Phone + Seperator;
    ClientRecord += to_string(ClientData.AccountBalance);

    return ClientRecord;
}

void SaveClientsDataToFile(vector<strClient>& vClients) {
    fstream File;
    string Line;
    File.open(ClientsFileName, ios::out);

    if (File.is_open()) {
        for (strClient& Client : vClients) {
            Line = ConvertRecordToLine(Client);
            File << Line << endl;
        }
        File.close();
    }
}

void DeleteClientByAccountNumber(string& AccountNumber) {

    vector<strClient> vClients = LoadClientsDataFromFileToVector(ClientsFileName);

    short index;

    if (FindClientIndexByAccountNumber(AccountNumber, vClients, index) ){

        PrintClientData(vClients.at(index));

        if (ConfirmDelete()) {

            if (index == vClients.size() - 1) {
                vClients.pop_back();
            }
            else {
                for (short j = index; j < vClients.size() - 1; j++) {
                    vClients.at(j) = vClients.at(j + 1);
                }
                vClients.pop_back();
            }

            SaveClientsDataToFile(vClients);

            cout << "Client Delete Successfuly.\n";
        }
    }
    else {
        cout << "Client with account number (" << AccountNumber << ")not found !\n";
    }
}

int main()
{
  string AccountNumber= ReadClientAccountNumber();
  DeleteClientByAccountNumber(AccountNumber);
  
}

