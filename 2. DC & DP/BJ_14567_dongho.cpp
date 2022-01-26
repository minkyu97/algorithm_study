#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int* arr;
int** Marr;


int main(void) {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;
    cin >> M;

    arr = new int[N+1]{0};
    for(int i=1; i<=N; i++) arr[i]=1;
    Marr = new int*[N+1];
    for(int i=0; i<N+1; i++) Marr[i]=new int[N+1]{0};

    for(int i=1; i<=M; i++) {
        int row,col;
        cin >> row;
        cin >> col;
        Marr[row][col]=1;
    }

    for(int i=2; i<=N; i++) {
        int max=0;
        for(int j=1; j<i; j++) {
            if(Marr[j][i]==1)
                if(max<arr[j])max=arr[j];
        }
        arr[i]+=max;
    }

    for(int i=1; i<=N; i++) cout << arr[i] << " ";

}










