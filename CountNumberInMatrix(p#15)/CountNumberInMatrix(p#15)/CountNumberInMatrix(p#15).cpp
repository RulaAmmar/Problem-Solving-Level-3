

#include <iostream>
using namespace std;

int ReadNumber(string Message) {
	int Number;
	cout << Message;
	cin >> Number;
	return Number;
}

void FillMatrixWithNumber(int Matrix[3][3], short Rows, short Cols) {

	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			cin >> Matrix[i][j];
		}
	}
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			cout << Matrix[i][j] << "\t";
		}
		cout << "\n";
	}
}

short CountNumberInMatrix(int Matrix[3][3],short Rows,short Cols,short CountNumber) {

	short Count = 0;

	for (short i = 0; i < Rows;i++) {
		for (short j = 0; j < Cols;j++) {
			if (Matrix[i][j] == CountNumber) {
				Count++;
			}
		}
	}
	return Count;
}

int main()
{
	//int Matrix[3][3] = { {9,0,0},{0,9,0},{0,0,0} };

	int Matrix[3][3];

	FillMatrixWithNumber(Matrix, 3, 3);

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix, 3, 3);

	int CountNumber=ReadNumber("\nEnter the number to count in matrix :");

	cout << "\nNumber " << CountNumber << " Count in matrix is " << CountNumberInMatrix(Matrix, 3, 3, CountNumber)<<endl;
	
}


