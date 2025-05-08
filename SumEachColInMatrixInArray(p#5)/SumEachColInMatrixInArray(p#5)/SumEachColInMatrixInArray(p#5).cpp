

#include <iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

int RandomNumber(int From, int To) {
    int RandNum;
    RandNum = rand() % (To - From + 1) + 1;
    return RandNum;
}

void FillMatrixWithRandomNumber(int Arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            Arr[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int Arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            cout << setw(3) << Arr[i][j] << "\t";
        }
        cout << "\n";
    }
}

int ColSum(int arr[3][3], short Rows, short ColNumber)
{
    int Sum = 0;
    for (short i = 0; i <= Rows - 1; i++)
    {
        Sum += arr[i][ColNumber];
    }
    return Sum;
}

void SumEachColInMatrixInArray(int Arr[3][3], int SumArray[3], short Cols,short Rows) {
    for (short i = 0; i < Cols;i++) {
        SumArray[i] = ColSum(Arr,Rows, i);
    }
}

void PrintColSumArray(int SumArr[3],short Length) {

    cout << "\nThe the following are the sum of each col in the matrix:\n";

    for (short i = 0; i < Length;i++) {
        cout << "Col " << i + 1 << " Sum = " << SumArr[i] << endl;
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

    SumEachColInMatrixInArray(Arr, SumArr, 3, 3);

    PrintColSumArray(SumArr,3);


}


