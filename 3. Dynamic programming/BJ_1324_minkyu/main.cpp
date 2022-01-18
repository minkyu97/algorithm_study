#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;
using matrix = vector<vector<int> >;

int N, input;
// 쓰레기 위치를 인덱스로 첫째날 쓰레기 기록 (위치는 1부터 시작)
vector<int> trash;
// 쓰레기 크기를 인덱스로 둘째날 쓰레기 기록
matrix mem(50001);
// 가장 최근에 집은 쓰레기의 위치에 대한 결과를 저장
matrix results;

int solve(int beforeIndex, int beforeIndexOfSecond) {
    if (beforeIndex == N) return 0;
    if (results[beforeIndex][beforeIndexOfSecond]) return results[beforeIndex][beforeIndexOfSecond];
    int ret = 0;
    for (int i = beforeIndex + 1; i <= N; i++) {
        if (trash[i] > trash[beforeIndex] && mem[trash[i]].size() != 0) {
            int secondIndex = 1001;
            for (int index: mem[trash[i]]) {
                if (index > beforeIndexOfSecond) {
                    secondIndex = index;
                    break;
                }
            }
            if (secondIndex == 1001) continue;
            int temp = 1 + solve(i, secondIndex);
            ret = temp > ret ? temp : ret;
        }
    }
    results[beforeIndex][beforeIndexOfSecond] = ret;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    mem[0].push_back(0);
    trash = vector<int>(N+1);
    results = matrix(N+1, vector<int>(N+1));
    for (int i = 0; i < N; i++) {
        cin >> trash[i+1];
    }
    for (int i = 0; i < N; i++) {
        cin >> input;
        mem[input].push_back(i+1);
    }

    cout << solve(0, 0) << endl;
}