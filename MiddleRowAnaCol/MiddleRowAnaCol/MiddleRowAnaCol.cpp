

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

void PrintMiddleRowOfMatrix(int Arr[3][3],short Cols,short Rows) {

	short MiddRow = Rows / 2;

	for (short i = 0; i < Cols;i++) {

		printf("%02d\t", Arr[MiddRow][i]) ;
	}
}

void PrintMiddleColOfMatrix(int Arr[3][3],short Rows,short Cols) {

	short MiddCol = Cols / 2;

	for (short i = 0; i < Rows;i++) {

		printf("%02d\t", Arr[i][MiddCol]);
	}
}

void PrintArray(int Arr[3],short Length) {
	for (short i = 0; i < Length;i++) {
		printf("%02d\t",Arr[i]);
	}
}

int main()
{
	int Matrix[3][3];

	int ArrMiddleRow[3];

	int ArrMiddleCol[3];

	srand(time(NULL));

	FillMatrixWithRandomNumber(Matrix, 3, 3);

	cout << "Matrix1: " << endl;

	PrintMatrix(Matrix, 3, 3);


	cout << "\nMiddle row of matrix1 is : \n";
	PrintMiddleRowOfMatrix(Matrix, 3, 3);

	cout << "\n\nMiddle row of matrix1 is : \n";
	PrintMiddleColOfMatrix(Matrix, 3, 3);
	
}

