#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>



using namespace std;

int factorial(int n) {
    if(n<=1) return 1;
    else return n* factorial(n-1);
}

int getNumOfSolution(int** matrix, int row, int col, int startR, int startC, bool pastIsGaro) {

    int numOfCrystal=0;
    int numOfImpurities=0;


    //보석과 불순물의 수 계산
    for(int i=startR; i<startR+row; i++) {
        for(int j=startC; j<startC+col; j++){
            if(matrix[i][j]==1) numOfImpurities++;
            if(matrix[i][j]==2) numOfCrystal++;
        }
    }

//    cout << "size:" << row << "x" << col
//         << " startRC:" << startR << " " << startC
//         <<" numofCandI:"<< numOfCrystal << " " << numOfImpurities << endl;

    //자른게 망한 상황, 잘 자른 상황의 기저 케이스
    if(numOfCrystal==0) return 0;
    if(numOfCrystal==1) {
        if(numOfImpurities==0) return 1;
        else return 0;
    }
    if(numOfImpurities==0) return 0;




    //아직 다 안 자른 상황
    int sol=0;

    //행을 자르는 경우
    if(!pastIsGaro) {

        for (int i = startR + 1; i < startR + row - 1; i++) {
            //행이 두 개 이하면 못자른다
            if (row <= 2) continue;
            //보석이 있는 줄을 자를 수는 없다
            bool CrystalInline = false;
            for (int j = startC; j < startC + col; j++) if (matrix[i][j] == 2) CrystalInline = true;
            if (CrystalInline) continue;
            //불순물이 없는 줄을 자를 수는 없다
            bool isImpuritiesInLine = false;
            for (int j = startC; j < startC + col; j++) if (matrix[i][j] == 1) isImpuritiesInLine = true;
            if (!isImpuritiesInLine) continue;
            //cout << i <<"번째 행 자름" << endl;

            int left = getNumOfSolution(matrix, i - startR, col, startR, startC, true);
            int right = getNumOfSolution(matrix, row - i + startR - 1, col, i + 1, startC, true);
            sol += left * right;

        }
    }
        //열을 자르는 경우
    else {
        for (int j = startC + 1; j < startC + col - 1; j++) {
            //열이 두 개 이하면 못 자른다
            if (col <= 2) continue;
            //보석이 있는 줄을 자를 수는 없다
            bool CrystalInline = false;
            for (int i = startR; i < startR + row; i++) if (matrix[i][j] == 2) CrystalInline = true;
            if (CrystalInline) continue;
            //불순물이 없는 줄을 자를 수는 없다
            bool isImpuritiesInLine = false;
            for (int i = startR; i < startR + row; i++) if (matrix[i][j] == 1) isImpuritiesInLine = true;
            if (!isImpuritiesInLine) continue;
            //cout << j <<"번째 열 자름" << endl;

            int left = getNumOfSolution(matrix, row, j - startC, startR, startC, false);
            int right = getNumOfSolution(matrix, row, col - j + startC - 1, startR, j + 1, false);
            sol += left * right;



        }
    }

    return sol;

}

int main(void) {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sizeOfSlate;
    cin >> sizeOfSlate;

    int** matrix = new int *[sizeOfSlate];
    for(int i=0; i<sizeOfSlate; i++) {
        matrix[i]= new int[sizeOfSlate]{0};
    }

    for(int i=0; i<sizeOfSlate; i++) {
        for(int j=0; j<sizeOfSlate; j++) {
            cin >> matrix[i][j];
        }
    }

    int sol = getNumOfSolution(matrix, sizeOfSlate, sizeOfSlate, 0,0, true) + getNumOfSolution(matrix, sizeOfSlate, sizeOfSlate, 0,0, false);
    if(sol==0) cout << -1;
    else cout << sol;



    return 0;
}










