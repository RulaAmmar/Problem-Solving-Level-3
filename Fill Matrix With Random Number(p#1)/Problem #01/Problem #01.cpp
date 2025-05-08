

#include <iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

int RandomNumber(int From,int To) {

	int RandNum;

	RandNum = rand() % (To - From+1)+From;

	return RandNum;
}

void FillMatrixWithRandomNumber(int Arr[3][3],short Rows,short Cols) {
	for (short i = 0; i < Rows;i++) {
		for (short j = 0; j < Cols;j++) {
			Arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int Arr[3][3],short Rows,short Cols) {
	for (short i = 0; i < Rows;i++) {
		for (short j = 0; j < Cols;j++) {
			cout <<setw(3)<< Arr[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{
	int Matrix[3][3];

	srand(time(NULL));

	FillMatrixWithRandomNumber(Matrix,3,3);

	cout << "the folwing is a 3*3 random matrix: " << endl;

	PrintMatrix(Matrix,3,3);
}

