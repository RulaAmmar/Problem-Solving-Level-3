

#include <iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

int RandomNumber(int From,int To) {

	int RandNum;

	RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

void FillMatrixWithRandomNumber(int Arr[3][3],short Rows,short Cols) {
	for (short i = 0; i < Rows;i++) {
		for (short j = 0; j < Cols;j++) {
			Arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int Arr[3][3],short Rows,short Cols) {
	for (short i = 0; i < Rows;i++) {
		for (short j = 0; j < Cols;j++) {
			cout << setw(3)<<Arr[i][j] << "\t";
		}
		cout << "\n";
	}
}

int RowSum(int Arr[3][3], short RowNumber,short Cols) {

	int Sum = 0;

	for (short i = 0; i < Cols; i++) {
		Sum += Arr[RowNumber][i];
	}

	return Sum;
}

//void PrintEachRowSum(int Arr[3][3],short Cols,short Rows) {
//
//	cout << "\nThe the following are the sum of each row in the matrix:\n";
//
//	for (short i = 0; i < Rows;i++) {
//		cout << "Row " << i + 1 << " Sum = " << RowSum(Arr, i, Cols) << endl;
//	}
//}

void SumEachRowInMatrixInArray(int SumArray[3],int Arr[3][3],short Rows,short Cols) {

	for (short i = 0; i < Rows; i++) {

		SumArray[i] = RowSum(Arr, i, Cols);
	}
}

void PrintSumEachRowInArray(int SumArr[3],short Rows) {

	cout << "\nThe the following are the sum of each row in the matrix:\n";

	for (short i = 0; i < Rows;i++) {
		cout<<"Row "<<i+1<<" Sum = " << SumArr[i]<<endl;
	}
}

int main()
{
	int Arr[3][3];

	int SumArr[3];

	srand((unsigned)time(NULL));

	FillMatrixWithRandomNumber(Arr, 3, 3);

	cout << "The following is a 3x3 random matrix:\n";

	PrintMatrix(Arr, 3, 3);

	SumEachRowInMatrixInArray(SumArr,Arr,3,3);

	PrintSumEachRowInArray(SumArr, 3);
}


