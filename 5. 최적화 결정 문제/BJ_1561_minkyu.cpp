#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int N, M;
vector<long long> rides;

bool decision(long long n) {
    long long ret = 0;
    for (int i = 1; i <= M; i++) {
        ret += ceil(n / (double)rides[i]);
    }
    return ret >= N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    rides = vector<long long>(M+1);
    for (int i = 1; i <= M; i++) cin >> rides[i];

    if (M >= N) {
        cout << N;
        return 0;
    }

    // 아래 for문이 끝나면 모든 아이들이 빠짐없이 놀이기구를 타는데 hi분이 걸리는 것을 알 수 있음
    long long lo = 0;
    long long hi = 1e15;
    long long mid;
    for (int i = 0; i < 100; i++) {
        mid = (lo + hi) / 2;
        if (decision(mid)) hi = mid;
        else lo = mid;
    }

    // 이제 hi분을 기준으로 가장 마지막에 탄 놀이기구가 무엇인지 찾으면 됨
    long long child = 0;
    for (int i = 1; i <= M; i++) {
        child += ceil(mid / (double)rides[i]);
    }
    for (int i = 1; i <= M; i++) {
        if (mid % rides[i] == 0) {
            if (++child == N) {
                cout << i << endl;
                return 0;
            }
        }
    }
}