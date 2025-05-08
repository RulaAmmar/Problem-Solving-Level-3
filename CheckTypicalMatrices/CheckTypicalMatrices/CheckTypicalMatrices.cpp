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

bool AreTypicalMatrices(int Matrix1[3][3],int Matrix2[3][3],short Cols,short Rows) {

	for (short i = 0; i < Rows;i++) {
		for (short j = 0; j < Cols;j++) {
			if (Matrix1[i][j] != Matrix2[i][j]) {
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int Matrix1[3][3], Matrix2[3][3];

	srand((unsigned)time(NULL));

	FillMatrixWithRandomNumber(Matrix1, 3, 3);
	cout << "Matrix1: " << endl;
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumber(Matrix2, 3, 3);
	cout << "\nMatrix2: " << endl;
	PrintMatrix(Matrix2, 3, 3);

	if (AreTypicalMatrices(Matrix1, Matrix2, 3, 3)) {
		cout << "\nY: Matrices are Typical\n";
	}
	else {
		cout << "\nN: Matrices are not Typical\n";
	}
}
