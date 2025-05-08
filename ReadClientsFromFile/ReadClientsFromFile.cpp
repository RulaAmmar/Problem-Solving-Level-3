

#include <iostream>
#include<fstream>
#include <vector>
#include <string>
#include<iomanip>
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

vector<strClient> LoadClientsDataFromFileToVector(const string &FileName) {

    fstream ClientsFile;
    string Line;

    vector<strClient> vClients;
    strClient Client;

    ClientsFile.open(FileName, ios::in);

    if (ClientsFile.is_open()) {
        while (getline(ClientsFile,Line)) {
           Client =ConvertDataLineToRecord(Line);
           vClients.push_back(Client);
}
    }
    else {
        cout << "\nThere is a problem with the file, it was not read\n";
    }

    return vClients;
}

void PrintClientData(const strClient &Client) {
    cout<<"| " << left<<setw(16) << Client.AccountNumber;
    cout << "| " <<left<< setw(11) << Client.PinCode;
    cout << " | " << left << setw(35) << Client.Name;
    cout << "| " << left << setw(16) << Client.Phone;
    cout << "| " << left << setw(10) << Client.AccountBalance;
}

void PrintAllClientsData(vector<strClient> &vClients) {

    cout << "\t\t\t\t\t Client List (" << vClients.size()<< ")" << " Client(s).\n\n";
    cout << "-----------------------------------------------------------------------------------------------------\n\n";
    cout << "| " << left << setw(16) << "Account Number";
    cout << "| " << left << setw(11) << "Pin Code";
    cout << "| " << left << setw(35) << "Client Name";
    cout << "| " << left << setw(16) << "Phone";
    cout << "| " << left << setw(10) << "Balance"<<"\n\n";
    cout << "-----------------------------------------------------------------------------------------------------\n\n";

    for (strClient &Client:vClients) {
        PrintClientData(Client);
        cout << "\n";
    }

    cout << "\n-----------------------------------------------------------------------------------------------------\n\n";
}

int main()
{
    vector<strClient> vClients=LoadClientsDataFromFileToVector(ClientsFileName);

    PrintAllClientsData(vClients);
}

