#include <iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

int RandomNumber(int From, int To) {

	int RandNum;

	RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

void FillMatrixWithRandomNumber(int Arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			Arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrix(int Arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			printf("%02d\t", Arr[i][j]);
		}
		cout << endl;
	}
}

int SumOfMatrix(int Arr[3][3], short Rows, short Cols) {

	int Sum = 0;

	for (short i = 0; i < Rows; i++) {

		for (short j = 0; j < Cols; j++) {
			Sum += Arr[i][j];
		}
	}
	return Sum;
}

bool CheckSumOfMatricesEquality(int Arr1[3][3],int Arr2[3][3],short Rows,short Cols) {

	return (SumOfMatrix(Arr1, Rows, Cols) == SumOfMatrix(Arr2, Rows, Cols));
	
}

int main()
{
	int Matrix1[3][3],Matrix2[3][3];

	srand((unsigned)time(NULL));

	FillMatrixWithRandomNumber(Matrix1, 3, 3);
	cout << "Matrix1: " << endl;
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumber(Matrix2, 3, 3);
	cout << "\nMatrix2: " << endl;
	PrintMatrix(Matrix2, 3, 3);

	if (CheckSumOfMatricesEquality(Matrix1, Matrix2, 3, 3)) {
		cout << "\nYes: Matrices Are Equal\n";
	}
	else {
		cout << "\nNo : Matrices Are Not Equal\n";
	}
}
