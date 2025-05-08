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

int SumOfMatrix(int Arr[3][3],short Rows,short Cols) {

	int Sum = 0;

	for (short i = 0; i < Rows;i++) {

		for (short j = 0; j < Cols;j++) {
			Sum += Arr[i][j];
		}
	}
	return Sum;
}

int main()
{
	int Matrix[3][3];

	srand((unsigned)time(NULL));

	FillMatrixWithRandomNumber(Matrix, 3, 3);

	cout << "Matrix1: " << endl;

	PrintMatrix(Matrix, 3, 3);

	cout << "\nSum of matrix1 is : " << SumOfMatrix(Matrix, 3, 3)<<endl;
}
