//
// Created by 진성찬 on 2022/01/08.
//

#include <iostream>
using namespace std;
int N, *T, *P;

int revenue(int start) {
    int on, off;
    if(start >= N) return 0;
    if(start + T[start] > N) on = 0;
    else on = P[start] + revenue(start+T[start]);
    off = revenue(start+1);
    return max(on, off);
}

int main() {
    cin >> N;
    T = new int[N];
    P = new int[N];
    for(int i = 0; i < N; i++) {
        cin >> T[i] >> P[i];
    }
    cout << revenue(0);
}