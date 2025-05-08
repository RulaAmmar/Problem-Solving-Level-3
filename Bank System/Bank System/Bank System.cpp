

#include <iostream>
#include <fstream>
#include<vector>
#include<string>
#include<iomanip>


using namespace std;

const string FileName = "ClientsFile.txt";

void ShowMainMenu();

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

enum enMainMenueOptions
{
    eClientList = 1,
    eAddNewClient = 2,
    eDeleteClient = 3,
    eUpdateClient = 4,
    eFindClient = 5,
    eExit = 6
};

short ReadOption() {

    short Option;

    cout << "Choose what do you want to do? [1 to 6] ?";

    cin >> Option;

    return  Option;
}

vector<string> SplitString(string Text, string Seperator = "#//#") {

    short Pos;
    string sWord;
    vector<string> vString;

    while ((Pos = Text.find(Seperator)) != string::npos) {
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

sClient ConvertDataLineToRecord(string& Text, string Seperator = "#//#") {
    vector<string> vString = SplitString(Text, Seperator);

    sClient Client;

    Client.AccountNumber = vString.at(0);
    Client.PinCode = vString.at(1);
    Client.Name = vString.at(2);
    Client.Phone = vString.at(3);
    Client.AccountBalance = stod(vString.at(4));

    return Client;
}

vector<sClient> LoadClientsDataFromFile() {

    fstream File;
    string DataLine;

    sClient Client;

    vector<sClient> vClients;

    File.open(FileName, ios::in);

    if (File.is_open()) {
        while (getline(File, DataLine)) {
            Client = ConvertDataLineToRecord(DataLine);
            vClients.push_back(Client);
        }
        File.close();
    }
    return vClients;
}

void PrintClientRecord(sClient& Client) {
    cout << "| " << setw(18) << left << Client.AccountNumber;
    cout << "| " << setw(13) << left << Client.PinCode;
    cout << "| " << setw(32) << left << Client.Name;
    cout << "| " << setw(18) << left << Client.Phone;
    cout << "| " << setw(13) << left << Client.AccountBalance;
}

void ShowAllClientsScreen() {

    system("color 8f");

    vector<sClient> vClients = LoadClientsDataFromFile();

    cout << "\n\n\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n-------------------------------------------------------------";
    cout << "---------------------------------------------------\n" << endl;
    cout << "| " << setw(18) << left << "Account Number";
    cout << "| " << setw(13) << left << "Pin Code";
    cout << "| " << setw(32) << left << "Client Name";
    cout << "| " << setw(18) << left << "Phone";
    cout << "| " << setw(13) << left << "Balance";
    cout << "\n-------------------------------------------------------------";
    cout << "---------------------------------------------------\n" << endl;

    if (vClients.size() == 0) {
        cout << "\t\t\t\tNo Client Available In The System !";
    }
    else {

        for (sClient& Client : vClients) {
            PrintClientRecord(Client);
            cout << endl;
        }

    }
    cout << "\n-------------------------------------------------------------";
    cout << "---------------------------------------------------\n" << endl;
}

bool IsClientExistByAccountNumber(string& AccountNumber, sClient& Client) {

    fstream ClientsFile;

    ClientsFile.open(FileName, ios::in);

    if (ClientsFile.is_open()) {

        string Line;
        sClient C;

        while (getline(ClientsFile, Line)) {

            C = ConvertDataLineToRecord(Line);

            if (C.AccountNumber == AccountNumber) {
                ClientsFile.close();
                Client = C;
                return true;
            }
        }
        ClientsFile.close();
        return false;

    }
    else {
        cout << "\nThere is problem for open the file.";
        return false;
    }
}

sClient ReadNewClientData() {
    sClient Client;
    sClient C;

    cout << "Enter Account Number ? ";
    getline(cin >> ws, Client.AccountNumber);

    while (IsClientExistByAccountNumber(Client.AccountNumber, C)) {
        cout << "\n\nClient With [" << Client.AccountNumber << "] already Exists,Enter Another Account Number ?";

        getline(cin, Client.AccountNumber);

    }
    cout << "\nEnter PinCode ? ";
    getline(cin, Client.PinCode);

    cout << "\nEnter Name ? ";
    getline(cin, Client.Name);

    cout << "\nEnter Phone ? ";
    getline(cin, Client.Phone);

    cout << "\nEnter AccountBalance ? ";
    cin >> Client.AccountBalance;

    return Client;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#") {
    string Line;

    Line += Client.AccountNumber + Seperator;
    Line += Client.PinCode + Seperator;
    Line += Client.Name + Seperator;
    Line += Client.Phone + Seperator;
    Line += to_string(Client.AccountBalance);

    return Line;
}

void AddDataLineToFile(const string& LineData) {

    fstream ClientsFile;

    ClientsFile.open(FileName, ios::app);

    if (ClientsFile.is_open()) {
        ClientsFile << LineData << endl;
        ClientsFile.close();
    }
    else {
        cout << "There is problem in open the file\n";
    }
}

void AddNewClient() {

    AddDataLineToFile(ConvertRecordToLine(ReadNewClientData()));
}

void AddNewClients() {

    char Answer;

    do {

        cout << "\nAdding New Client : \n\n";

        AddNewClient();

        cout << "Client Added Successfuly, do you want to add more clients?Y/N?";

        cin >> Answer;
    } while (tolower(Answer) == 'y');
}

void ShowAddNewClientsScreen() {
    system("color df");

    cout << "\n---------------------------------------------\n";
    cout << "\tAdd New Clients Screen";
    cout << "\n---------------------------------------------\n";

    AddNewClients();
}

string ReadAccountNumber() {
    string AccountNumber;
    cout << "Please Enter Account Number?";
    getline(cin >> ws, AccountNumber);
    return AccountNumber;
}

void PrintClientCard(sClient& Client) {

    cout << "\nThe Following Are The Client Details : \n";
    cout << "------------------------------------------------\n";
    cout << left << setw(16) << "Account Number" << ":" << Client.AccountNumber << endl;
    cout << left << setw(16) << "Pin Code" << ":" << Client.PinCode << endl;
    cout << left << setw(16) << "Name" << ":" << Client.Name << endl;
    cout << left << setw(16) << "Phone" << ":" << Client.Phone << endl;
    cout << left << setw(16) << "Account Balance" << ":" << Client.AccountBalance << endl;
    cout << "------------------------------------------------\n\n";
}

void DeleteClientByAccountNumber(string AccountNumber) {
    sClient Client;

    if (!IsClientExistByAccountNumber(AccountNumber, Client)) {
        cout << "\nClient With Account Number(" << AccountNumber << ") Is Not Found!\n";
    }
    else {
        char Answer;
        PrintClientCard(Client);

        cout << "\nAre You Sure You Want Delete This Client?Y/N?";
        cin >> Answer;

        if (tolower(Answer) == 'y') {

            fstream NewFile;
            fstream ClientsFile;
            string DataLine;
            sClient Client;

            NewFile.open("TempFile.txt", ios::out);
            ClientsFile.open(FileName, ios::in);

            if (NewFile.is_open() && ClientsFile.is_open()) {
                while (getline(ClientsFile, DataLine)) {
                    Client = ConvertDataLineToRecord(DataLine);
                    if (Client.AccountNumber == AccountNumber) {
                        continue;
                    }
                    DataLine = ConvertRecordToLine(Client);
                    NewFile << DataLine << endl;
                }
                NewFile.close();
                ClientsFile.close();
                remove("ClientsFile.txt");
                rename("TempFile.txt", "ClientsFile.txt");
                cout << "\n\n\nClient Delete Successfully\n\n";
            }
            else {
                cout << "\n\nThere Is Problem For Open The File\n\n";
            }
        }

    }

}

void ShowDeleteClientScreen() {

    system("color B0");

    cout << "------------------------------------------------\n";
    cout << "\t  Delete Client Screen\n";
    cout << "------------------------------------------------\n\n";

    DeleteClientByAccountNumber(ReadAccountNumber());

}

sClient ReadUpdatedClientData(string& AccountNumber) {

    sClient UpdatedClient;

    UpdatedClient.AccountNumber = AccountNumber;

    cout << "\n\nEnter New Pin Code : ";
    getline(cin >> ws, UpdatedClient.PinCode);

    cout << "Enter New Name : ";
    getline(cin, UpdatedClient.Name);

    cout << "Enter New Phone : ";
    getline(cin, UpdatedClient.Phone);

    cout << "Enter New Account Balance : ";
    cin >> UpdatedClient.AccountBalance;

    return UpdatedClient;
}

void SaveDataToFile(vector<sClient>& vClients) {
    fstream ClientsFile;
    string DataLine;

    ClientsFile.open(FileName, ios::out);

    if (ClientsFile.is_open()) {
        for (sClient& Client : vClients) {
            DataLine = ConvertRecordToLine(Client);
            ClientsFile << DataLine << endl;
        }
        ClientsFile.close();
    }
    else {
        cout << "\nThere Is Problem For Open The File!!\n";
    }
}

void UpdateClientInfoByAccountNumber(string AccountNumber) {

    char Answer;
    sClient Client;
    string DataLine;
    vector<sClient> vClients;

    if (!IsClientExistByAccountNumber(AccountNumber, Client)) {
        cout << "\nClient With Account Number (" << AccountNumber << ") Is Not Found !\n";
    }
    else {
        PrintClientCard(Client);

        cout << "\n\nAre You Sure You Want Update This Client?Y/N?";
        cin >> Answer;
        if (tolower(Answer) == 'y') {

            fstream ClientsFile;
            ClientsFile.open(FileName, ios::in);

            if (ClientsFile.is_open()) {
                while (getline(ClientsFile, DataLine)) {
                    Client = ConvertDataLineToRecord(DataLine);
                    if (Client.AccountNumber == AccountNumber) {
                        Client = ReadUpdatedClientData(AccountNumber);
                    }
                    vClients.push_back(Client);

                }
                ClientsFile.close();

                SaveDataToFile(vClients);
                cout << "\n\nClient Updated Successfully\n";
            }
            else {
                cout << "\nThere Is Problem For Open The File!!\n";
            }
        }

    }
}

void ShowUpdateClientInfoScreen() {

    system("color E0");

    cout << "------------------------------------------\n";
    cout << "\tUpdate Client Info Screen\n";
    cout << "------------------------------------------\n";

    UpdateClientInfoByAccountNumber(ReadAccountNumber());
}

bool IsClientEmpty(sClient& Client) {
    return Client.AccountNumber.empty();
}

sClient FindClientByAccountNumber(string AccountNumber) {

    sClient Client;

    if (!IsClientExistByAccountNumber(AccountNumber, Client)) {
        cout << "\n\nClient With Account Number (" << AccountNumber << ") Is Not Found!\n\n";
    }
    return Client;
}

void ShowFindClientScreen() {

    system("color 83");

    cout << "------------------------------------------\n";
    cout << "\tShow Find Client Screen\n";
    cout << "------------------------------------------\n";

    sClient Client = FindClientByAccountNumber(ReadAccountNumber());

    if (!IsClientEmpty(Client)) {
        PrintClientCard(Client);
    }
}

void ShowExitScreen() {

    system("Color 7D");

    cout << "------------------------------------------\n";
    cout << "\tProgram Ends :-)\n";
    cout << "------------------------------------------\n";
}

void GoBackToMainMenu() {
    cout << "\nPress any key to go back to Main Menu...";
    system("pause>0");
    system("cls");
    ShowMainMenu();
}

void ExecuteMainMenuOption(enMainMenueOptions MainMenuOption) {

    switch (MainMenuOption) {
    case enMainMenueOptions::eClientList:
        system("cls");
        ShowAllClientsScreen();
        GoBackToMainMenu();
        break;
    case enMainMenueOptions::eAddNewClient:
        system("cls");
        ShowAddNewClientsScreen();
        GoBackToMainMenu();
        break;
    case enMainMenueOptions::eDeleteClient:
        system("cls");
        ShowDeleteClientScreen();
        GoBackToMainMenu();
        break;
    case enMainMenueOptions::eUpdateClient:
        system("cls");
        ShowUpdateClientInfoScreen();
        GoBackToMainMenu();
        break;
    case enMainMenueOptions::eFindClient:
        system("cls");
        ShowFindClientScreen();
        GoBackToMainMenu();
        break;
    default:
        system("cls");
        ShowExitScreen();
    }
}

void ShowMainMenu() {

    system("Color 9F");

    cout << "=================================================\n\n";
    cout << "\t\tMain Menu Screen\n\n";
    cout << "=================================================\n";
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Exit.\n";
    cout << "=================================================\n";

    ExecuteMainMenuOption((enMainMenueOptions)ReadOption());

}

int main()
{

    ShowMainMenu();

}
