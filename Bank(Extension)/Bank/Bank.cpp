
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
const string ClientsFileName = "Clients.txt";

void ShowMainMenue();
void ShowTransactionsMenueScreen();

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};

vector<string> SplitString(string S1, string Delim) {

	vector<string> vString;
	short pos = 0;
	string sWord;


	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1);
	}

	return vString;
}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
	sClient Client;
	vector<string> vClientData;
	vClientData = SplitString(Line, Seperator);

	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);
	return Client;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{

	string stClientRecord = "";
	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.AccountBalance);
	return stClientRecord;
}

bool ClientExistsByAccountNumber(string AccountNumber, string FileName) {

	vector <sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line;
		sClient Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertLinetoRecord(Line);
			if (Client.AccountNumber == AccountNumber)
			{
				MyFile.close();
				return true;
			}
		}

		MyFile.close();

	}
	return false;
}

sClient ReadNewClient() {

	sClient Client;
	cout << "Enter Account Number? ";

	getline(cin >> ws, Client.AccountNumber);

	while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName))
	{
		cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
		getline(cin >> ws, Client.AccountNumber);
	}

	cout << "Enter PinCode? ";
	getline(cin, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client.Name);

	cout << "Enter Phone? ";
	getline(cin, Client.Phone);

	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;

	return Client;
}

vector <sClient> LoadCleintsDataFromFile(string FileName) {

	vector <sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line;
		sClient Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertLinetoRecord(Line);
			vClients.push_back(Client);
		}
		MyFile.close();
	}
	return vClients;
}

void PrintClientRecordLine(sClient Client) {
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowAllClientsScreen() {
	vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	if (vClients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In the System!";
	else

		for (sClient Client : vClients)
		{

			PrintClientRecordLine(Client);
			cout << endl;
		}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}

void PrintClientCard(sClient Client) {
	cout << "\nThe following are the client details:\n";
	cout << "-----------------------------------";
	cout << "\nAccout Number: " << Client.AccountNumber;
	cout << "\nPin Code     : " << Client.PinCode;
	cout << "\nName         : " << Client.Name;
	cout << "\nPhone        : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
	cout << "\n-----------------------------------\n";
}

bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& Client) {

	for (sClient &C : vClients)
	{

		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}

	}
	return false;
}

sClient ChangeClientRecord(string AccountNumber) {
	sClient Client;

	Client.AccountNumber = AccountNumber;

	cout << "\n\nEnter PinCode? ";
	getline(cin >> ws, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client.Name);

	cout << "Enter Phone? ";
	getline(cin, Client.Phone);

	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;
	return Client;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients) {

	for (sClient& C : vClients)
	{

		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForDelete = true;
			return true;
		}

	}

	return false;
}

vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);//overwrite

	string DataLine;

	if (MyFile.is_open())
	{
		for (sClient C : vClients)
		{

			if (C.MarkForDelete == false)
			{
				//we only write records that are not marked for delete.  
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}

		}

		MyFile.close();
	}

	return vClients;
}

void AddDataLineToFile(string FileName, string  stDataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{

		MyFile << stDataLine << endl;

		MyFile.close();
	}
}

void AddNewClient()
{
	sClient Client;
	Client = ReadNewClient();
	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void AddNewClients()
{
	char AddMore = 'Y';
	do
	{
		//system("cls");
		cout << "Adding New Client:\n\n";

		AddNewClient();
		cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');

}

bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
	sClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{

		PrintClientCard(Client);

		cout << "\n\nAre you sure you want delete this client? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
			SaveCleintsDataToFile(ClientsFileName, vClients);

			//Refresh Clients 
			vClients = LoadCleintsDataFromFile(ClientsFileName);

			cout << "\n\nClient Deleted Successfully.";
			return true;
		}

	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		return false;
	}
}

bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{

	sClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{

		PrintClientCard(Client);
		cout << "\n\nAre you sure you want update this client? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			for (sClient& C : vClients)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C = ChangeClientRecord(AccountNumber);
					break;
				}
			}

			SaveCleintsDataToFile(ClientsFileName, vClients);

			cout << "\n\nClient Updated Successfully.";
			return true;
		}

	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		return false;
	}
}

string ReadClientAccountNumber()
{
	string AccountNumber = "";

	cout << "\nPlease enter AccountNumber? ";
	cin >> AccountNumber;
	return AccountNumber;

}

void ShowDeleteClientScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tDelete Client Screen";
	cout << "\n-----------------------------------\n";

	vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	DeleteClientByAccountNumber(AccountNumber, vClients);
}

void ShowUpdateClientScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tUpdate Client Info Screen";
	cout << "\n-----------------------------------\n";

	vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	UpdateClientByAccountNumber(AccountNumber, vClients);

}

void ShowAddNewClientsScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tAdd New Clients Screen";
	cout << "\n-----------------------------------\n";

	AddNewClients();
}

void ShowFindClientScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tFind Client Screen";
	cout << "\n-----------------------------------\n";

	vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
	sClient Client;
	string AccountNumber = ReadClientAccountNumber();
	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
		PrintClientCard(Client);
	else
		cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";
}

void ShowEndScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tProgram Ends :-)";
	cout << "\n-----------------------------------\n";
}

enum enMainMenueOptions
{
	eListClients = 1, eAddNewClient = 2,
	eDeleteClient = 3, eUpdateClient = 4,
	eFindClient = 5, eTransaction=6 ,eExit = 7
};

void GoBackToMainMenue()
{
	cout << "\n\nPress any key to go back to Main Menue...";
	system("pause>0");
	ShowMainMenue();

}

short ReadMainMenueOption()
{
	cout << "Choose what do you want to do? [1 to 7]? ";
	short Choice = 0;
	cin >> Choice;

	return Choice;
}

short ReadTansActionsMenueOption() {

	short Option;
	cout << "Choose what do you want to do? [1 to 4]? ";
	cin >> Option;
	return Option;
}

enum enTransActionsMenueOption
{
	eDeposit = 1, eWithdraw = 2, eTotalBalances = 3, eMainMenue = 4
};

double ReadAmount(string Message) {

	double  Amount;
	cout << Message;
	cin >> Amount;

	return Amount;
}

bool ConfirmTransaction() {

	char Answer;

	cout << "Are you sure you want perform this transaction? y/n? ";
	cin >> Answer;

	if (tolower(Answer) == 'y') {
		return true;
	}
	else {
		return false;
	}
}

 double DepositBalanceToClientByAccountNumber(string AccountNumber,double DepositAmount,vector<sClient> &vClients) {

	for (sClient& Client : vClients) {

		if (Client.AccountNumber == AccountNumber) {
			Client.AccountBalance += DepositAmount;
			return Client.AccountBalance;
		}

	}
}

void ShowDepositScreen() {

	system("color 79");

	cout << "\n-----------------------------------\n";
	cout << "\tDeposit Screen";
	cout << "\n-----------------------------------\n";

	string AccountNumber = ReadClientAccountNumber();
	vector<sClient> vClients = LoadCleintsDataFromFile("Clients.txt");
	sClient Client;

	while (!FindClientByAccountNumber(AccountNumber, vClients, Client)) {
		cout << "\nClient with account number [" << AccountNumber << "] dose not exist.";
		AccountNumber = ReadClientAccountNumber();
	}

	PrintClientCard(Client);

	double DepositAmount = ReadAmount("Please enter deposit amount?");

	if (ConfirmTransaction()) {

		double NewBalance=DepositBalanceToClientByAccountNumber(AccountNumber, DepositAmount, vClients);
		
		SaveCleintsDataToFile("Clients.txt", vClients);
		cout << endl << "Done Successfuly, New Balance Is : " <<NewBalance<< "\n";
	}

}

void GoBackTransactionsMenue() {
	cout << "\n\nPress any key to go back to transactions menue...... ";
	system("pause>0");
	ShowTransactionsMenueScreen();
}

void ShowClientBalanceInfo(sClient& Client) {

	cout << "| " << left << setw(17) << Client.AccountNumber;
	cout << "| " << left << setw(35) << Client.Name;
	cout << "| " << left << setw(32) << Client.AccountBalance;
}

void ShowBalancesListClients() {

	system("color 57");

	vector<sClient> vClients = LoadCleintsDataFromFile("Clients.txt");

	cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(17) << "Account Number";
	cout << "| " << left << setw(35) << "Client Name";
	cout << "| " << left << setw(32) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;


	double TotalBalances = 0;

	for (sClient& Client : vClients) {
		ShowClientBalanceInfo(Client);
		TotalBalances += Client.AccountBalance;
		cout << "\n";
	}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n";

	cout << "\n\t\t\t\t\tTotal Balances = " << TotalBalances<<endl;

}

bool IsAmountExceedsBalance(double &Amount,double &AccountBalance) {
	 
	return Amount > AccountBalance ? true : false;
}

void ShowWithdrawScreen() {

	system("color f0");

	cout << "\n-----------------------------------\n";
	cout << "\tWithdraw Screen";
	cout << "\n-----------------------------------\n";

	string AccountNumber = ReadClientAccountNumber();

	vector<sClient> vClients = LoadCleintsDataFromFile("Clients.txt");
	sClient Client;

    while(!FindClientByAccountNumber(AccountNumber, vClients, Client )) {

		cout << "\nClient with account number [" << AccountNumber << "] dose not exist.";
		AccountNumber = ReadClientAccountNumber();
	}

	PrintClientCard(Client);

	double WithdrawAmount = ReadAmount("Please enter withdraw amount?");

	while (IsAmountExceedsBalance(WithdrawAmount, Client.AccountBalance)) {

		cout << "\n\nAmount Exceeds The Balance, You Can Withdraw Up To : " << Client.AccountBalance << endl;

		WithdrawAmount=ReadAmount("Please Enter Another Amount?");
	}

	if (ConfirmTransaction()) {

		double NewBalance = DepositBalanceToClientByAccountNumber(AccountNumber, WithdrawAmount*-1, vClients);

		SaveCleintsDataToFile("Clients.txt", vClients);

		cout << endl << "Done Successfuly, New Balance Is : " << NewBalance << "\n";
	}
}

void ExecuteTransactionsMenueOption(enTransActionsMenueOption TransActionsMenueOption) {

	switch (TransActionsMenueOption) {
	case enTransActionsMenueOption::eDeposit:
		system("cls");
		ShowDepositScreen();
		GoBackTransactionsMenue();
		break;
	case enTransActionsMenueOption::eTotalBalances:
		system("cls");
		ShowBalancesListClients();
		GoBackTransactionsMenue();
		break;
	case enTransActionsMenueOption::eWithdraw:
		system("cls");
		ShowWithdrawScreen();
		GoBackTransactionsMenue();
		break;
	case enTransActionsMenueOption::eMainMenue:
		ShowMainMenue();
	}
}

void ShowTransactionsMenueScreen() {

	
	system("cls");
	system("color 80");
	cout << "\n========================================\n";
	cout << "\tTansActions Menue Screen";
	cout << "\n========================================\n";
	cout << "\t[1] Deposit.\n";
	cout << "\t[2] Withdraw.\n";
	cout << "\t[3] Total Balances.\n";
	cout << "\t[4] Main Menue.\n";
	cout << "========================================\n";

	ExecuteTransactionsMenueOption((enTransActionsMenueOption)ReadTansActionsMenueOption());
}

void PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
{
	switch (MainMenueOption)
	{
	case enMainMenueOptions::eListClients:
	{
		system("cls");
		ShowAllClientsScreen();
		GoBackToMainMenue();
		break;
	}
	case enMainMenueOptions::eAddNewClient:
		system("cls");
		ShowAddNewClientsScreen();
		GoBackToMainMenue();
		break;
	case enMainMenueOptions::eDeleteClient:
		system("cls");
		ShowDeleteClientScreen();
		GoBackToMainMenue();
		break;
	case enMainMenueOptions::eUpdateClient:
		system("cls");
		ShowUpdateClientScreen();
		GoBackToMainMenue();
		break;
	case enMainMenueOptions::eFindClient:
		system("cls");
		ShowFindClientScreen();
		GoBackToMainMenue();
		break;
	case enMainMenueOptions::eTransaction:
		system("cls");
		ShowTransactionsMenueScreen();
		break;
	case enMainMenueOptions::eExit:
		system("cls");
		ShowEndScreen();
		break;
	}
}

void ShowMainMenue()
{
	system("cls");
	system("color 30");

	cout << "===========================================\n";
	cout << "\t\tMain Menue Screen\n";
	cout << "===========================================\n";
	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Update Client Info.\n";
	cout << "\t[5] Find Client.\n";
	cout << "\t[6] Transactions.\n";
	cout << "\t[7] Exit.\n";
	cout << "===========================================\n";
	PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}

int main()
{
	ShowMainMenue();
	
}