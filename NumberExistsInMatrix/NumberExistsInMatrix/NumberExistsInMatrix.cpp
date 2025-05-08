

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

//bool IsNumberExistsInMatrix(int Matrix[3][3], short Rows,short Cols,short CheckNumber) {//??? ??????? ????? ???
//	return CountNumberInMatrix(Matrix, Rows, Cols,CheckNumber);
//}

bool IsNumberExistsInMatrix(int Matrix[3][3],short Rows,short Cols,short CheckNumber) {
	for (short i = 0; i < Rows;i++) {
		for (short j = 0; j < Cols;j++) {
			if (Matrix[i][j] == CheckNumber) {
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int Matrix[3][3] = { {9,0,0},{0,9,0},{0,0,0} };

	cout << "Matrix1:\n";
	PrintMatrix(Matrix, 3, 3);

	short Number;
	cout << "\nPlease Enter the number to look for in matrix : ";
	cin >> Number;

	if (IsNumberExistsInMatrix(Matrix, 3, 3, Number))
		cout << "\nYes it is there\n";
	else
		cout<< "\nNo it is not there\n";

}


