

#include <iostream>
using namespace std;

void FillMatrixWithNumber(int Matrix[3][3], short Rows, short Cols) {

	for (short i = 0; i < Rows;i++) {
		for (short j = 0; j < Cols;j++) {
			cin >> Matrix[i][j];
		}
	}
}

void PrintMatrix(int Matrix[3][3],short Rows,short Cols) {
	for (short i = 0; i < Rows;i++) {
		for (short j = 0; j < Cols;j++) {
			cout << Matrix[i][j] << "\t";
		}
		cout << "\n";
	}
}

bool IsScalarMatrix(int Matrix[3][3],short Rows,short Cols) {

	short DiagonalNum = Matrix[0][0];

	for (short i = 0; i < Rows;i++) {
		for (short j = 0; j < Cols;j++) {
			if (i == j && Matrix[i][j] != DiagonalNum) {
				return false;
			}
			else if (i!=j&&Matrix[i][j]!=0) {
				return false;
			}
		}
	}
	return true;
}

int main()
{
	//int Matrix[3][3] = { {9,0,0},{0,9,0},{0,0,0} };

	int Matrix[3][3];

	FillMatrixWithNumber(Matrix, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrix(Matrix,3,3);

	if (IsScalarMatrix(Matrix,3,3)) {
		cout << "\nY: Matrix is scalar\n";
	}
	else {
		cout << "\nNo: Matrix is not scalar\n";
	}
}


