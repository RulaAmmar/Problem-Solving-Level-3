
#include <iostream>
#include<cstdlib>
using namespace std;

int RandomNumber(int From,int To) {
	int RandNum;

	RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

void FillMatrixWithRandomNumber(int Arr[3][3],short Rows,short Cols) {
	for (short i = 0; i < Rows;i++) {
		for (short j = 0; j < Cols;j++) {
			Arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrix(int Arr[3][3],short Rows,short Cols) {
	for (short i = 0; i < Rows;i++) {
		for (short j = 0; j < Cols;j++) {
			printf("%02d\t",Arr[i][j]);
		}
		cout << "\n";
	}
}

void MultiplyTowMatrix(int Matrix1[3][3],int Matrix2[3][3],int ResultMatrix[3][3],short Rows,short Cols) {
	for (short i = 0; i < Rows;i++) {
		for (short j = 0; j < Cols;j++) {
			ResultMatrix[i][j] = Matrix1[i][j] * Matrix2[i][j];
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3],Matrix2[3][3], ResultMatrix[3][3];


	FillMatrixWithRandomNumber(Matrix1, 3, 3);

	FillMatrixWithRandomNumber(Matrix2, 3, 3);

	cout << "Matrix1: \n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMatrix2: \n";
	PrintMatrix(Matrix2, 3, 3);

	MultiplyTowMatrix(Matrix1, Matrix2, ResultMatrix, 3, 3);

	cout << "\nResults: \n";
	PrintMatrix(ResultMatrix, 3, 3);
}


