#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N, P;
int cost[16][16];
int on[16];
int off[16];
int ret[65536];

void memoize(int c, int minimum) {
    int index = 0;
    for(int i = 0; i < c; i++) {
        index += (int) pow(2, on[i]);
    }
    ret[index] = minimum;
}

int memoization(int c) {
    int index = 0;
    for(int i = 0; i < c; i++) {
        index += (int) pow(2, on[i]);
    }
    return ret[index];
}

int answer(int C) {
    if(C == 0) {
        if(P == 0) return 0;
        else return -1;
    }
    if(P <= C) return 0;
    if(memoization(C) != -1) return memoization(C);

    int minimum = (P - C) * 36;
    for(int j = 0; j < N - C; j++) {
        int select = 36;
        for(int i = 0; i < C; i++) {
            if(cost[on[i]][off[j]] < select) {
                select = cost[on[i]][off[j]];
            }
        }
        on[C] = off[j];
        for(int i = j + 1; i < N - C; i++) {
            off[i-1] = off[i];
        }
        int count = select + answer(C+1);
        minimum = min(minimum, count);
        for(int i = N - C - 1; i > j; i--) {
            off[i] = off[i-1];
        }
        off[j] = on[C];
    }
    memoize(C, minimum);
    return minimum;
}

int main() {
    for(int i = 0; i < 65536; i++) ret[i] = -1;

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            cin >> cost[i][j];
    }

    char s;
    int C = 0;
    for(int i = 0; i < N; i++) {
        cin >> s;
        if(s == 'Y') on[C++] = i;
        else off[i-C] = i;
    }
    cin >> P;

    cout << answer(C);
}