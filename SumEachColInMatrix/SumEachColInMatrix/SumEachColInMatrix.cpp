

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

int ColSum(int Arr[3][3],short Rows,short ColNumber) {

    int Sum = 0;
    for (short i = 0; i < Rows; i++) {
        Sum += Arr[i][ColNumber];
    }
    return Sum;
}

void PrintSumEachColInMatrix(int Arr[3][3],short Cols,short Rows) {

    cout << "\nthe following are the sum of each col in the matrix:\n";

    for (short i = 0; i < Cols;i++) {
        cout << "Col " << i + 1<< " Sum = " << ColSum(Arr, Rows, i) << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Arr[3][3];

    cout << "The following is a 3x3 random matrix:\n";

    FillMatrixWithRandomNumber(Arr, 3, 3);

    PrintMatrix(Arr, 3, 3);

    PrintSumEachColInMatrix(Arr, 3, 3);
}


