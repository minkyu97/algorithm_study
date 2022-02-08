#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N, M;
int *crane, *box;

int main() {
    cin >> N;
    crane = new int[N];
    for(int i = 0; i < N; i++) {
        cin >> crane[i];
    }
    sort(crane, crane+N);

    cin >> M;
    box = new int[M];
    for(int i = 0; i < M; i++) {
        cin >> box[i];
    }
    sort(box, box+M);

    if(crane[N-1] < box[M-1]) {
        cout << -1;
        return 0;
    }

    if(N == 1) {
        cout << M;
        return 0;
    }

    int *loadable = new int[M];
    int start = N-2;
    for(int i = M-1; i >= 0; i--) {
        bool done = false;
        for(int j = start; j >= 0; j--) {
            if(box[i] > crane[j]) {
                loadable[i] = N - j - 1;
                start = j;
                done = true;
                break;
            }
        }
        if(!done) {
            for(int j = i; j >= 0; j--) {
                loadable[j] = N;
            }
            break;
        }
    }

    int ans = 1;
    for(int i = 2; i <= M; i++) {
        int tmp = i/loadable[M-i] + (i % loadable[M-i] != 0);
        if(tmp > ans) ans = tmp;
    }
    cout << ans;
}