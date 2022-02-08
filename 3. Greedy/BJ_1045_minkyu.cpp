#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

struct Road {
    int i;
    int j;
};

int N, M;
const int MAX_N = 50;
vector<Road> road;
int result[50];

Road pop(vector<Road>& road) {
    Road ret = road.front();
    road.erase(road.begin());
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    // 이건 좀;;
    if (N == 1 && M == 0) {
        cout << 0 << endl;
        return 0;
    }
    memset(&result, 0, 50 * sizeof(int));

    road = vector<Road>();
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = i; j < N; j++) {
            if (row[j] == 'Y') {
                road.push_back(Road{i, j});
            }
        }
    }
    
    if (road.size() < M) {
        cout << -1 << endl;
        return 0;
    }

    Road r = pop(road);
    result[r.i]++;
    result[r.j]++;
    int visited = 2;

    for (vector<Road>::iterator it = road.begin(); it != road.end(); it++) {
        if (result[it->i] == 0 && result[it->j] == 0) continue;
        if (result[it->i] != 0 && result[it->j] != 0) continue;
        result[it->i]++;
        result[it->j]++;
        road.erase(it);
        visited++;
        if (visited == N) break;
        it = road.begin() - 1;
    }

    if (visited != N) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < M-N+1; i++) {
        result[road[i].i]++;
        result[road[i].j]++;
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << ' ';
    }
    cout << endl;
    return 0;
}