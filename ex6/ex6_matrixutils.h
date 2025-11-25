#ifndef EX6_MATRIXUTILS_H
#define EX6_MATRIXUTILS_H

using namespace std;

int** allocateMatrix(int n);
void freeMatrix(int** a, int n);
void fillSequential(int** a, int n);
void printMatrix(int** a, int n);
void swapDiagonalsInPlace(int** a, int n);

#endif //EX6_MATRIXUTILS_H