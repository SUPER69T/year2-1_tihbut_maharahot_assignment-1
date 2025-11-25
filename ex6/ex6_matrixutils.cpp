#include "ex6_matrixutils.h"
#include <iostream>

using namespace std;

int** allocateMatrix(int size){
    int** matrix = new int*[size];
    for(int i = 0; i < size; ++i){
        matrix[i] = new int[size];
    }
    return matrix;
}

void freeMatrix(int** a, int size){
    for(int i = 0; i < size; ++i){
        delete[] a[i];
    }
    delete[] a;
}

void fillSequential(int** a, int n){
    int value = n;
    for(int i = 0; i < sizeof(a[0]); i++){
        for(int j = 0; j < sizeof(a[0]); j++){
            a[i][j] = value;
            value++;
        }
    }
}

void printMatrix(int** a, int size){
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            cout << a[i][j] << "\t";
        }
        cout << "\n";
    }
}

void swapDiagonalsInPlace(int** a, int size){
    for(int i = 0; i < size; ++i){
        int temp = a[i][i];
        a[i][i] = a[i][size - i - 1];
        a[i][size - i - 1] = temp;
    }
}