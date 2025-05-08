#include <iostream>
#include<iomanip>
using namespace std;

void PrintMatrix(int Arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			printf("%d\t", Arr[i][j]);
		}
		cout << endl;
	}
}

short CountNumberInMatrix(int Matrix[3][3], short Rows, short Cols, short CountNumber) {

	short Count = 0;

	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (Matrix[i][j] == CountNumber) {
				Count++;
			}
		}
	}
	return Count;
}

bool IsSparceMatrix(int Matrix[3][3],short Rows,short Cols) {

	short MatrixSize = Rows*Cols;

	return (CountNumberInMatrix(Matrix, 3, 3, 0) > MatrixSize / 2);
}

int main()
{
	int Matrix1[3][3] = { {0,0,0},{8,8,8},{0,0,0} };

	cout << "Matrix1: " << endl;
	PrintMatrix(Matrix1, 3, 3);

	if (IsSparceMatrix(Matrix1, 3, 3)) {
		cout << "\nYes: it is sparce\n";
	}
	else {
		cout << "\nNo: it is not sparce\n";
	}
	
}
