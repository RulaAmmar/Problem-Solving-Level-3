#include <iostream>
using namespace std;

void PrintMatrix(int Arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			printf("%d\t", Arr[i][j]);
		}
		cout << endl;
	}
}

bool IsIdentityMatrix(int Matrix[3][3],short Cols,short Rows) {
	for (short i = 0; i < Rows;i++) {

		for (short j = 0; j < Cols;j++) {

			if (i == j&&Matrix[i][j]!=1) {

					return false;
			}
			
			else if(i!=j&&Matrix[i][j]!=0) {
					return false;
			 }

			}

		}
	return true;
	}

int main()
{
	int Matrix[3][3] = { {1,0,0},{0,1,0},{0,0,1} };


	cout << "Matrix: " << endl;
	PrintMatrix(Matrix, 3, 3);

	if (IsIdentityMatrix(Matrix, 3, 3) ){
		cout<<"\nYes: Matrix is identity\n";
	}
	else {
		cout << "\nNo: Matrix is not identity\n";
	}
}
