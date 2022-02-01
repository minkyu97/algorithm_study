#include <iostream>
#include <vector>
#include <cmath>
#define endl '\n'
#define MAX 987654321
#define MIN -987654321

using namespace std;
using matrix = vector<vector<int> >;
using mat3d = vector<matrix>;

int N, M, K;
int cpu[100], mem[100], prt[100];
int totalcpu = 0, totalmem = 0, totalpri = 0;
matrix cache;

int cpuindex(int cpu) {
    if(cpu < M) return cpu;
    else return M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;
    cache = matrix(M+1, vector<int>(500, MIN));
    for (int i = 0; i < N; i++) {
        cin >> cpu[i] >> mem[i] >> prt[i];
        totalcpu += cpu[i];
        totalmem += mem[i];
        totalpri += prt[i];
    }
    if (totalcpu < M || totalmem < K) {
        cout << -1 << endl;
        return 0;
    }
    if (totalcpu == M || totalmem == K) {
        cout << totalpri << endl;
        return 0;
    }

    cache[cpu[0]][prt[0]] = mem[0];
    cache[0][0] = 0;
    for (int i = 1; i < N; i++) {
        for (int j = M; j != -1; j--) {
            for (int k = totalpri; k != -1; k--) {
                if (cache[j][k] == MIN) continue;
                cache[cpuindex(j+cpu[i])][k+prt[i]] = max(cache[cpuindex(j+cpu[i])][k+prt[i]], cache[j][k] + mem[i]);
            }
        }
    }

    for (int i = 0; i <= 500; i++) {
        if (cache[M][i] >= K) {
            cout << i << endl;
            return 0;
        }
    }
}