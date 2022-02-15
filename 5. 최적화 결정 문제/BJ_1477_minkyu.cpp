#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int N, M, L;
vector<int> station;
vector<int> distances;

// 모든 간격이 low 이상으로 가능?
bool decision(double low) {
    int howmany = 0;
    for (int d: distances) {
        howmany += ceil(d / low)-1;
    }
    return howmany <= M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> L;
    if (N == 0) {
        cout << ceil(L/(double)(M+1)) << endl;
        return 0;
    }
    station = vector<int>(N);
    distances = vector<int>(N+1);
    for (int i = 0; i < N; i++) cin >> station[i];
    sort(station.begin(), station.end());
    distances[0] = station[0];
    for (int i = 1; i < N; i++) {
        distances[i] = station[i] - station[i-1];
    }
    distances[N] = L - station[N-1];

    double lo = -1, hi = 2001;
    double mid;
    for (int i = 0; i < 100; i++) {
        mid = (lo + hi) / 2;
        if (decision(mid)) hi = mid;
        else lo = mid;
    }
    
    // 반드시 올림 해야됨
    cout << ceil(mid) << endl;
}