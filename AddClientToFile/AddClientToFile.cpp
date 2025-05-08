

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct strClientData
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

strClientData ReadClientData() {

    strClientData ClientData;

    cout << "Account Number : ";
    getline(cin>>ws, ClientData.AccountNumber);

    cout << "PinCode : ";
    getline(cin, ClientData.PinCode);

    cout << "Name : ";
    getline(cin, ClientData.Name);

    cout << "Phone : ";
    getline(cin, ClientData.Phone);

    cout << "Account Balance : ";
    cin >> ClientData.AccountBalance;

    return ClientData;
}

string ConvertRecordToLine(strClientData ClientData,string Seperator) {
    
    string DataLine;
    DataLine += ClientData.AccountNumber + Seperator;
    DataLine += ClientData.PinCode + Seperator;
    DataLine += ClientData.Name + Seperator;
    DataLine += ClientData.Phone + Seperator;
    DataLine += to_string(ClientData.AccountBalance);

    return DataLine;
}

void AddDataLineToFile(string DataLine) {

    fstream MyFile;

    MyFile.open("MyFile.txt", ios::out | ios::app);

   if( MyFile.is_open() ){
       MyFile << DataLine << endl;
       MyFile.close();
    }
}

void AddNewClient() {

    AddDataLineToFile(ConvertRecordToLine(ReadClientData(), "#//#"));
}

void AddClientsToFile() {

    char AddMore ;

    do {
        system("cls");
        cout << "Adding new client : \n\n";
        AddNewClient();
        cout << "Client Added successfuly,do you want to add more ?Y/N ?";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}

int main()
{
    
    AddClientsToFile();
}


