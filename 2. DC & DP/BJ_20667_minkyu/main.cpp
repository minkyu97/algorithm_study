#include <iostream>
#include <vector>
#define endl '\n'
#define MAX 987654321

using namespace std;
using matrix = vector<vector<int> >;
using mat3d = vector<matrix>;

int N, M, K;
int tab[100][3];
int totalcpu, totalmem, totalpri;
vector<int> closedTab;
matrix cache;

int cpuindex(int cpu) {
    if (cpu > M) return M+1;
    return cpu;
}

// start 이후부터 끌 수 있을 때, 앞으로 최소 몇의 중요도를 이용해서 조건을 만족시킬 수 있는지 반환
int solve(int start, int cpu, int memory) {
    if (cpu >= M && memory >= K) return 0;
    if (start == N) return MAX;
    int& ret = cache[start][0];
    int& retcpu = cache[start][1];
    int& retmem = cache[start][2];
    if (ret != MAX && retcpu >= cpu && retmem >= memory) return MAX;
    int temp = tab[start][2] + solve(start+1, cpu+tab[start][0], memory+tab[start][1]);
    if (temp != MAX) {
        if (temp < ret) {
            ret = temp;
            retcpu = cpu;
            retmem = memory;
        }
    }
    temp = solve(start+1, cpu, memory);
    if (temp != MAX) {
        if (temp < ret) {
            ret = temp;
            retcpu = cpu;
            retmem = memory;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;
    cache = matrix(N, vector<int>(3, MAX));
    for (int i = 0; i < N; i++) {
        cin >> tab[i][0] >> tab[i][1] >> tab[i][2];
        totalcpu += tab[i][0];
        totalmem += tab[i][1];
        totalpri += tab[i][2];
    }
    if (totalcpu < M || totalmem < K) {
        cout << -1 << endl;
        return 0;
    }
    if (totalcpu == M || totalmem == K) {
        return totalpri;
    }
    cout << solve(0, 0, 0) << endl;
}