#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using matrix = vector<map<int, int> >;

int N, M;
int A, B, C;
matrix bridge;
int f1, f2;

bool DFS(int start, int weight, vector<bool>& visited) {
    if (start == f2) return true;
    visited[start] = true;

    bool ret = false;
    for (pair<int, int> next: bridge[start]) {
        if (!visited[next.first] && next.second >= weight) ret = DFS(next.first, weight, visited);
        if (ret) return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    bridge = matrix(N+1);

    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        int& temp = bridge[A][B];
        temp = max(temp, C);
        bridge[B][A] = temp;
    }
    cin >> f1 >> f2;
    

    int lo = -1, hi = 1e9+1;
    int mid;
    for (int i = 0; i < 100; i++) {
        mid = (lo + hi) / 2;
        vector<bool> visited (N+1, false);
        if(DFS(f1, mid, visited)) lo = mid;
        else hi = mid;
    }
    cout << mid << endl;
}