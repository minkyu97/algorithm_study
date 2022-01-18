#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define endl '\n'
// 넉넉하게 무한대값 잡음
#define INF 100000

using namespace std;
using matrix = vector<vector<int> >;

int N, P;
matrix cost;
vector<bool> isOn;
vector<int> onList;
// 이 부분 매우 중요!! 65536이라는 숫자도, -1도 중요함
// 메모이제이션을 활용한 DP의 핵심 로직
vector<int> memory(65536, INF);

// 메모이제이션 안 된 부분 계산하는 로직.. 부분적인 완전탐색이라 어려울 건 없음
int getMinCostToTurnOn(int plant) {
    int minimum = INF;
    for (int onIndex: onList) {
        minimum = cost[onIndex][plant] < minimum ? cost[onIndex][plant] : minimum;
    }
    return minimum;
}

// 재귀적으로 solve하는 부분
// 완전탐색을 하면 O(N!) 이지만, 메모이제이션을 활용해서 시간 단축
// 얼마나 단축되는지는 좀 계산해봐야될 것 같음
int solve() {
    // 기저조건: size가 P가 되면 더 이상 비용이 들지 않음
    if(onList.size() == P) return 0;
    // 비트 해싱 기법을 통한 캐시값 탐색
    int mem_index = 0;
    for (int onIndex: onList) {
        mem_index += 1 << onIndex;
    }
    // ret을 캐시값의 참조변수로 설정
    int& ret = memory[mem_index];
    if (ret != INF) return ret;
    for (int i = 0; i < N; i++) {
        if (!isOn[i]) {
            int temp = getMinCostToTurnOn(i);
            isOn[i] = true;
            onList.push_back(i);
            temp += solve();
            ret = temp < ret ? temp : ret;
            isOn[i] = false;
            onList.pop_back();
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    cost = matrix(N, vector<int>(N));
    isOn = vector<bool>(N);
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> cost[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        char input;
        cin >> input;
        isOn[i] = (input == 'Y');
        if (isOn[i]) {
            onList.push_back(i);
        }
    }
    cin >> P;
    // 기저조건: 이미 충분히 켜져있는 경우
    if (onList.size() >= P) {
        cout << 0 << endl;
        return 0;
    }
    // 기저조건: 모두 꺼져있는 경우
    if (onList.size() == 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << solve() << endl;
    return 0;
}