

#include <iostream>

using namespace std;

void FillMatrixWithOrderedNumbers(int Arr[3][3], short Rows, short Cols) {
    short Counter = 0;
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            Counter++;
            Arr[i][j] = Counter;
        }
    }
}

void PrinMatrix(int Arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            cout << Arr[i][j] << "\t";
        }
        cout << "\n";
    }
}

void TransposeMatrix(int Arr[3][3],int TransposedArr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows;i++) {
        for (short j = 0; j < Cols;j++) {

            TransposedArr[j][i] = Arr[i][j];
        }
    }
}

int main()
{
    int Arr[3][3];

    int TransposedArr[3][3];

    FillMatrixWithOrderedNumbers(Arr, 3, 3);

    cout << "The following is a 3*3 ordered numbers : \n";

    PrinMatrix(Arr, 3, 3);

    TransposeMatrix(Arr,TransposedArr,3, 3);

    cout << "\nThe following is a Transposed matrix : \n";

    PrinMatrix(TransposedArr, 3, 3);
}


