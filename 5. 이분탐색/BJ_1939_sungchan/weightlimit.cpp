#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
int N, M;

int main() {
    cin >> N >> M;
    vector<map<int, int>> bridge(N+1);

    int A, B, C;
    for(int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        if(bridge[A].find(B) == bridge[A].end()) {
            bridge[A][B] = C;
            bridge[B][A] = C;
        } else if(C > bridge[A][B]) {
            bridge[A][B] = C;
            bridge[B][A] = C;
        }
    }

    int src, dest;
    cin >> src >> dest;

    bool* connected = new bool[N+1];
    int* limit = new int[N+1];
    int* neighbor = new int[N+1];
    connected[src] = true;
    for(int i = 1; i <= N; i++) {
        if(i == src) continue;
        if(bridge[i].find(src) != bridge[i].end()) {
            limit[i] = bridge[i].at(src);
            neighbor[i] = src;
        } else {
            limit[i] = -1;
        }
    }

    while(!connected[dest]) {
        int maximum = -1;
        int max_index = -1;
        for(int i = 1; i <= N; i++) {
            if(!connected[i] && limit[i] != -1) {
                if(limit[i] > maximum) {
                    maximum = limit[i];
                    max_index = i;
                }
            }
        }
        connected[max_index] = true;
        for(int i = 1; i <= N; i++) {
            if(!connected[i] && bridge[max_index].find(i) != bridge[max_index].end()) {
                if(bridge[max_index].at(i) > limit[i]) {
                    limit[i] = bridge[max_index].at(i);
                    neighbor[i] = max_index;
                }
            }
        }
    }

    int index = dest;
    int minimum = INT32_MAX;
    while(index != src) {
        minimum = min(minimum, limit[index]);
        index = neighbor[index];
    }
    cout << minimum;
}