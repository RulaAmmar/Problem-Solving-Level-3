
#include <iostream>
#include <string>

using namespace std;

struct strClientData
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    int AccountBalance;
};

strClientData ReadClientData() {

    strClientData ClientData;

    cout << "Please enter account number ?\n";
    getline(cin, ClientData.AccountNumber);

    cout << "\nPlease enter pin code ?\n";
    getline(cin, ClientData.PinCode);

    cout << "\nPlease enter Name ?\n" ;
    getline(cin, ClientData.Name);

    cout << "\nPlease enter phone ?\n";
    getline(cin, ClientData.Phone);

    cout << "\nPlease enter Account balance ?\n";
    cin >> ClientData.AccountBalance;

}

string ConvertRecordToOneLine(strClientData& ClientData, string Seperator) {

    string ClientRecord;

   ClientRecord+=  ClientData.AccountNumber + Seperator;
   ClientRecord += ClientData.PinCode + Seperator;
   ClientRecord += ClientData.Name + Seperator;
   ClientRecord += ClientData.Phone + Seperator;
   ClientRecord += to_string(ClientData.AccountBalance);

    return ClientRecord;
}

int main()
{

    cout << "Please enter client data : \n\n";

    strClientData ClientData=ReadClientData();

    cout << "\n\nClient record is saving is : \n";

    cout << ConvertRecordToOneLine(ClientData, "#//#") << endl;
}

