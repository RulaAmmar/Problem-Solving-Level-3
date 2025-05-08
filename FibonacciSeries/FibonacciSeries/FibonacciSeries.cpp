

#include <iostream>
using namespace std;

void PrintFiboncciSeriesWithLoop(short UserLimit) {
	short FirstNum = 0, SecondNum = 1;
	int Sum;
	cout << FirstNum << " " << SecondNum << " ";
	for (short i = 3; i <= UserLimit; i++) {
		Sum = FirstNum + SecondNum;
		cout << Sum << " ";
		FirstNum=SecondNum;
		SecondNum = Sum;
	}
}

int main()
{
	PrintFiboncciSeriesWithLoop(10);
}


