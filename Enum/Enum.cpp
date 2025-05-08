

#include <iostream>
using namespace std;

enum enGender
{
Femal=1,Male
};

int main()
{
	
	
	
	cout << "Please enter gender [1]:Femal,[2]:Male ?";
	
	

	int Gender;
	cin >> Gender;

	if ( Gender == Femal) {
		cout << "Femal\n";
	}
	else if (Gender == Male) {
		cout << "Male\n";
	}
	else {
		cout << "Not Male and not femal\n";
	}

	
}

