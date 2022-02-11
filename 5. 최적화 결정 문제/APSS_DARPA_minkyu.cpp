#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int C, N, M;
vector<double> settable;

bool decision(int cameras, double gap) {
    double limit = -1;
    int installed = 0;
    for (int i = 0; i < settable.size(); i++) {
        if (limit <= settable[i]) {
            installed++;
            limit = settable[i] + gap;
        }
    }
    return installed >= cameras;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> C;
    cout << fixed;
    cout.precision(2);
    while (C--) {
        cin >> N >> M;
        settable = vector<double>(M);
        for (int i = 0; i < M; i++) {
            cin >> settable[i];
        }
        cout << endl;
        double lo = 0, hi = 241;
        double mid;
        for (int i = 0; i < 100; i++) {
            mid = (lo + hi) / 2.0;
            if(decision(N, mid)) lo = mid;
            else hi = mid;
        }
        cout << lo << endl;
    }
}