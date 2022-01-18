#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>



using namespace std;
long long **multiplyMatrix(long long **m1, int row1, int col1, long long **m2, int row2, int col2);


long long** pow(long long** theMatrix, long long numOfPow, long long** identityMatrix, int sizeOfMatrix) {
    if(numOfPow==0) return identityMatrix;
    if(numOfPow%2>0) return multiplyMatrix(
                pow(theMatrix, numOfPow-1, identityMatrix, sizeOfMatrix), sizeOfMatrix, sizeOfMatrix,
               theMatrix, sizeOfMatrix, sizeOfMatrix);
    long long** half = pow(theMatrix, numOfPow/2, identityMatrix, sizeOfMatrix);
    return multiplyMatrix(half, sizeOfMatrix,sizeOfMatrix, half, sizeOfMatrix, sizeOfMatrix);
}



long long **allocateMatrix(int row, int col)
{
    long long **matrix = new long long*[row];
    for(int i = 0; i < row; ++i) {
        matrix[i] = new long long[col]{0};
    }
    return matrix;
}

long long **multiplyMatrix(long long **m1, int row1, int col1, long long **m2, int row2, int col2)
{
    if (col1 != row2)
        return nullptr;

    auto ret = allocateMatrix(row1, col2);

    int i,j,k;

    for(i = 0; i < row1; i++) {
        for(j = 0; j < col2; j++) {
            for(k = 0; k < col1; k++) {
                ret[i][j] += m1[i][k] * m2[k][j];
                ret[i][j] %=1000;
            }
        }
    }

    return ret;
}

int main(void) {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sizeOfMatrix;
    long long numOfPow;

    cin >> sizeOfMatrix;
    cin >> numOfPow;

    long long** identityMatrix = allocateMatrix(sizeOfMatrix, sizeOfMatrix);
    long long** theMatrix = allocateMatrix(sizeOfMatrix, sizeOfMatrix);
    long long** resultMatrix = allocateMatrix(sizeOfMatrix, sizeOfMatrix);

    for(auto i = 0; i < sizeOfMatrix; ++i) {
        for(auto j = 0; j < sizeOfMatrix; ++j) {
            resultMatrix[i][j]=0;
            if(i==j) identityMatrix[i][j]=1;
            else identityMatrix[i][j] = 0;
        }
    }

    for(auto i = 0; i < sizeOfMatrix; ++i) {
        for(auto j = 0; j < sizeOfMatrix; ++j) {
            cin >> theMatrix[i][j];
        }
    }

    resultMatrix = pow(theMatrix, numOfPow, identityMatrix, sizeOfMatrix);

    for(auto i = 0; i < sizeOfMatrix; ++i) {
        for(auto j = 0; j < sizeOfMatrix; ++j) {
            long long a =resultMatrix[i][j]%1000;
            cout << a << " ";
        }
        cout << endl;
    }


    return 0;
}










