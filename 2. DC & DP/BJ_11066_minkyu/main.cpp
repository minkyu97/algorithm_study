#include <iostream>
#include <vector>
#include <cmath>
#define endl '\n'
#define MAX 987654321

using namespace std;
using matrix = vector<vector<int> >;

int T, K;
// 각 챕터의 사이즈 저장 챕터 번호: 0 ~ K-1
vector<int> chapter;
// i번째부터 j번째 챕터를 합칠 수 있는 최소 비용 저장
matrix cache;
matrix sum;

int solve(const int& start, const int& end) {
    if (start >= end) return 0;
    else if (start + 1 == end) return chapter[start] + chapter[end];
    int& ret = cache[start][end];
    if (ret != MAX) return ret;
    for (int i = start; i < end; i++) {
        ret = min(solve(start, i) + solve(i+1, end) + sum[start][end], ret);
    }
    return ret;
}

void calcsum() {
    for (int i = 0; i < K; i++) {
        int temp = 0;
        for (int j = i; j < K; j++) {
            temp += chapter[j];
            sum[i][j] = temp;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> K;
        chapter = vector<int>(K);
        cache = matrix(K, vector<int>(K, MAX));
        sum = matrix(K, vector<int>(K));
        for (int j = 0; j < K; j++) {
            cin >> chapter[j];
        }
        calcsum();
        cout << solve(0, K-1) << endl;
    }
}