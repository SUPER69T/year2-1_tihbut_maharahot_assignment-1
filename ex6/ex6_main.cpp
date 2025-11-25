#include "ex6_matrixutils.h"
#include <iostream>

using namespace std;
////////////////////////// FUNCTIONS FOR QUESTION 6 //////////////////////////
int main(){
	cout << "================== Question 6 ==================\n" << endl;

	cout << "Enter a matrix size: " << endl;
	int size;
	cin >> size;

    int** matrix1 = allocateMatrix(size);
    printMatrix(matrix1, size);
    fillSequential(matrix1, 3); //filling with sequential numbers starting from 3.
    cout << "Matrix after filling with sequential numbers starting from 3:" << endl;
    printMatrix(matrix1, size);
    swapDiagonalsInPlace(matrix1, size);
    cout << "Matrix after swapping diagonals in place:" << endl;
    printMatrix(matrix1, size);
    freeMatrix(matrix1, size);
    return 0;
}   