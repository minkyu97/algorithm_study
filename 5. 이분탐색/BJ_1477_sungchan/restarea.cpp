#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int N, M, L;

int main() {
    cin >> N >> M >> L;
    int* rest = new int[N];
    for(int i = 0; i < N; i++) {
        cin >> rest[i];
    }
    sort(rest, rest+N);

    int* gap = new int[N+1];
    gap[0] = rest[0];
    for(int i = 1; i < N; i++) {
        gap[i] = rest[i] - rest[i-1];
    }
    gap[N] = L - rest[N-1];
    sort(gap, gap+(N+1), greater<>());
    int* index = new int[N+1];
    for(int i = 0; i <= N; i++) index[i] = 1;

    for(int i = 0; i < M; i++) {
        bool done = false;
        int max = ceil((double) gap[0] / (double) index[0]);
        for(int i = 1; i <= N; i++) {
            if(ceil((double) gap[i] / (double) index[i]) > max) {
                index[i]++;
                done = true;
                break;
            }
        }
        if(!done) index[0]++;
    }

    int ans = ceil((double) gap[0] / (double) index[0]);
    for(int i = 1; i <= N; i++) {
        int cand = ceil((double) gap[i] / (double) index[i]);
        if(cand > ans) ans = cand;
    }

    cout << ans;
}