

#include <iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

int RandomNumber(int From,int To) {
    int RandNum;
    RandNum = rand() % (To - From + 1) + 1;
    return RandNum;
}

void FillMatrixWithRandomNumber(int Arr[3][3],short Rows,short Cols) {
    for (short i = 0; i < Rows;i++) {
        for (short j = 0; j < Cols;j++) {
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

int RowSum(int Arr[3][3], short RowNumber, short Cols) {
    int Sum = 0;

    for (short i = 0; i < Cols; i++) {
        Sum += Arr[RowNumber][i];
    }
    return Sum;
}

void SumEachRowMatrixInArray(int Arr[3][3],int SumEachRow[3], short Rows,short Cols) {

    for (short i = 0; i < Rows; i++) {

        SumEachRow[i] = RowSum(Arr, i, Cols);
    }
}

void PrintSumEachRow(int SumEachRow[3], short Rows) {

    cout << "\nThe the following are the sum of each row in matrix:\n";

    for (int i = 0; i < Rows;i++) {
        cout << "Row " << i + 1 << " Sum = " << SumEachRow[i] << endl;
    }
}

int main()
{
    int Arr[3][3];

    int SumEachRow[3];

    srand((unsigned)time(NULL));
   
    FillMatrixWithRandomNumber(Arr, 3, 3);

    PrintMatrix(Arr, 3, 3);

    SumEachRowMatrixInArray(Arr,SumEachRow, 3, 3);

    PrintSumEachRow(SumEachRow, 3);

}


