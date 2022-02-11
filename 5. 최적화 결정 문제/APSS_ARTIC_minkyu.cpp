#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using matrix = vector<vector<double> >;

struct Point {
    double x, y;
};

int C, n;
vector<Point> base;
matrix dist;
vector<bool> visited;
vector<bool> decisioned;

bool decision(int here, double gap) {
    decisioned[here] = true;
    visited[here] = true;
    for (int i = 0; i < n; i++) {
        if (dist[here][i] < gap) {
            visited[i] = true;
        }
    }
    if (find(visited.begin(), visited.end(), 0) != visited.end()) {
        for (int i = 0; i < n; i++) {
            if (visited[i] && !decisioned[i]) return decision(i, gap);
        }
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed;
    cout.precision(2);
    cin >> C;
    while(C--) {
        cin >> n;
        base = vector<Point>();
        dist = matrix(n, vector<double>(n, 0));
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            base.push_back(Point{x, y});
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                double gap = pow(pow(abs(base[i].x-base[j].x), 2) + pow(abs(base[i].y-base[j].y), 2), 0.5);
                dist[i][j] = gap;
                dist[j][i] = gap;
            }
        }

        double lo = 0, hi = 2e6+1;
        double mid;
        for (int i = 0; i < 100; i++) {
            visited = vector<bool>(n, 0);
            decisioned = vector<bool>(n, 0);
            mid = (lo + hi) / 2.0;
            if (decision(0, mid)) hi = mid;
            else lo = mid;
        }
        cout << mid << endl;
    }
}