#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void makeBasicTriangle(int k, int x, int y);
char** arr;

int main(void) {
    int input;
    int k=0;

    cin >> input;
    input/=3;

    arr = new char*[3072];

    for(int i=0; i<3072; i++) {
        arr[i] = new char[6143];
    }

    int startPointX = input*3;


    int xSize=startPointX*2-1;
    int ySize=startPointX;

    for(int i=0; i<xSize; i++) {
        for(int j=0; j<ySize; j++) {
            arr[j][i]=' ';
        }
    }

    makeBasicTriangle(input, 0, startPointX-1);

    for(int i=0; i<ySize; i++) {
        for(int j=0; j<xSize; j++) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void makeBasicTriangle(int k, int row, int col) {
    //가장 작은 삼각형을 만든다.
    if(k==1) {
        arr[row][col]='*'; arr[row+1][col-1] = '*'; arr[row+1][col+1] = '*';
        arr[row+2][col-2]='*'; arr[row+2][col-1]='*';arr[row+2][col]='*';arr[row+2][col+1]='*';arr[row+2][col+2]='*';
    }
        //재귀호출
    else {
        int K= k/2;
        makeBasicTriangle(K, row, col);
        if(K==1) {
            makeBasicTriangle(K, row+3, col-3);
            makeBasicTriangle(K, row+3, col+3);
        }
        else {
            makeBasicTriangle(K, row+K*3,col-K*3);
            makeBasicTriangle(K, row+K*3,col+K*3);
        }

    }
}








