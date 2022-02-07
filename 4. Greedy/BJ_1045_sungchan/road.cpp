#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int N, M;

int main() {
    cin >> N >> M;
    int cnt = 0;
    char c;
    bool **connected = new bool*[N];
    bool impossible = false;
    for(int i = 0; i < N; i++) {
        bool impossible1 = true;
        connected[i] = new bool[N];
        for(int j = 0; j < N; j++) {
            cin >> c;
            if(c == 'Y') {
                connected[i][j] = true;
                cnt++;
                impossible1 = false;
            }
        }
        if(impossible1) impossible = true;
    }
    cnt /= 2;

    if(N == 1 && M == 0) {
        cout << 0;
        return 0;
    }
    if(cnt < M || impossible) {
        cout << -1;
        return 0;
    }

    bool *connect = new bool[N];
    int *road = new int[N];
    int total = 0;

    priority_queue<int, vector<int>, greater<>> cost;
    for(int i = 1; i < N; i++) {
        if(connected[0][i]) {
            connect[i] = true;
            road[0]++;
            road[i]++;
            total++;
            for(int j = 1; j < N; j++) {
                if(connected[i][j] && !connect[j]) {
                    cost.push(N*min(i, j)+max(i, j));
                }
            }
        }
    }

    while(!cost.empty() && total < N-1) {
        int a = cost.top();
        cost.pop();
        int b = a / N;
        int bb = a % N;
        if(!connect[b] || !connect[bb]) {
            road[b]++;
            road[bb]++;
            total++;
            connected[b][bb] = false;
            if(!connect[b]) {
                for(int i = 1; i < N; i++) {
                    if(connected[b][i] && !connect[i]) {
                        cost.push(N*min(b,i)+max(b,i));
                    }
                }
            } else { // !connect[bb]
                for(int i = 1; i < N; i++) {
                    if(connected[bb][i] && !connect[i]) {
                        cost.push(N*min(bb,i)+max(bb,i));
                    }
                }
            }
            connect[b] = connect[bb] = true;
        }
    }


    if(total < N-1) {
        cout << -1;
        return 0;
    }

    for(int i = 1; i < N-1; i++) {
        if(total == M) break;
        for(int j = i+1; j < N; j++) {
            if(total == M) break;
            if(connected[i][j]) {
                road[i]++;
                road[j]++;
                total++;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        cout << road[i] << " ";
    }
}