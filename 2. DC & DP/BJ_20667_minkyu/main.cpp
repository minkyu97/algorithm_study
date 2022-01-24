#include <iostream>
#include <vector>
#include <cmath>
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

// start이전의 탭들은 어떤 걸 끄고 켤지 이전 재귀에서 결정이 되었다.
// 그 동안 사용한 중요도와 얻은 cpu, memory를 인자로 받았다.
// cache에 기록된 것보다 현재 상황이 나아졌다면, 계속 나아간다.
// 아니라면, 잘못된 선택이므로 MAX를 반환한다.
void solve(int start, int cpu, int memory, int priority) {
    if (start == N) return;
    if (cpu >= M && memory >= K) {
        cache[start][0] = cpu;
        cache[start][1] = memory;
        cache[start][2] = priority;
        return;
    }
    int& cachecpu = cache[start][0];
    int& cachemem = cache[start][1];
    int& cachepri = cache[start][2];
    if (cachecpu >= min(cpu, M) && cachemem >= min(cpu, K) && priority >= cachepri) return;
    if (cpu >= min(cachecpu, M) && memory >= min(cachemem, K) && priority <= cachepri) {
        cachecpu = cpu;
        cachemem = memory;
        cachepri = priority;
    }
    solve(start+1, cpu+tab[start][0], memory+tab[start][1], priority+tab[start][2]);
    solve(start+1, cpu, memory, priority);
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

    solve(0, 0, 0, 0);

    int minpri = MAX;
    for (int i = 0; i < N; i++) {
        if (cache[i][0] >= M && cache[i][1] >= K && cache[i][2] < minpri) minpri = cache[i][2];
    }

    cout << minpri << endl;
}