#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>


using namespace std;

int N, P;
string YNs;
int** costArr;
int cashe[1 << 17];



int getCost(int state, int numOfOnPlant) {
    if(numOfOnPlant >= P) {
        return 0;
    }
    if(numOfOnPlant==0) return -1;


    int& ret = cashe[state];
    if(ret!=-1) {
        return ret;
    }

    ret = 1000000000;
    //현 상태에서 켜져있는 발전소가 꺼져있는 발전소를 찾아 불을 킨 상태들에게 getCost함수를 호출해서 기존의 값과 비교한다.
    for(int i=0; i<N; i++) {
        if(state&(1<<i)) {
            for(int j=0; j<N; j++) {
                if(i==j) continue;
                if( (state&(1 << j)) ==0) {
                    ret = min(ret, getCost((state | (1<<j)), numOfOnPlant+1)+costArr[i][j]);
                }
            }
        }
    }

    return ret;

}

int main(void) {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    costArr= new int*[N]{0};
    for(int i =0; i<N; i++) costArr[i]=new int[N];
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> costArr[i][j];
        }
    }

    int state=0;
    int numOfY=0;

    cin >> YNs;
    for(int i=0; i<N; i++) {
        if(YNs[i]=='Y') {
            state |= (1<<i);
            numOfY++;
        }
    }

    cin >> P;

    for(int i=0; i<(1<<17); i++) cashe[i]=-1;

    cout << getCost(state, numOfY);

    return 0;
}










