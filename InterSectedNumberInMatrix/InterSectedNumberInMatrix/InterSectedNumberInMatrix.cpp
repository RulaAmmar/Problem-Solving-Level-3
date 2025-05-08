

#include <iostream>
using namespace std;

void PrintMatrix(int Matrix[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			cout << Matrix[i][j] << "\t";
		}
		cout << "\n";
	}
}

bool IsNumberExistsInMatrix(int Matrix[3][3], short Rows, short Cols, short CheckNumber) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (Matrix[i][j] == CheckNumber) {
				return true;
			}
		}
	}
	return false;
}

void PrintIntersectedNumberInMatrix(int Matrix1[3][3],int Matrix2[3][3],short Rows,short Cols) {

	short Number;

	for (short i = 0; i < Rows;i++) {
		for (short j = 0; j < Cols;j++) {
			Number = Matrix1[i][j];
			if (IsNumberExistsInMatrix(Matrix2, Rows, Cols, Number)) {
				cout << Number << "\t";
			}
		}
	}
}

int main()
{
	int Matrix1[3][3] = { {9,8,1},{0,9,5},{0,0,0} };
	int Matrix2[3][3] = { {8,8,9},{0,1,2},{7,0,5} };

	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	cout << "\nIntersected Number are : \n";
	PrintIntersectedNumberInMatrix(Matrix1, Matrix2, 3, 3);
}


