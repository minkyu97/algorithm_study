#include <iostream>
#include <vector>
#define endl '\n'
#define MAX 10000000

using namespace std;
using matrix = vector<vector<int> >;

int C, n;
matrix cache;

// 현재 층에 cur개 있을 때 n개의 조각을 위로 쌓아올려가면서 만들 수 있는 모노폴리의 수
int countMonoPoly(int cur, int rest) {
    if (rest==0) return 1;
    int& ret = cache[cur][rest];
    if (ret) return ret;
    for (int i = 1; i <= rest; i++) {
        ret += countMonoPoly(i, rest-i) * (cur + i - 1);
        if (ret > MAX) ret %= MAX;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> C;
    for (int j = 0; j < C; j++) {
        cin >> n;
        cache = matrix(n, vector<int>(n, 0));
        int result = 0;
        for (int i = 1; i <= n; i++) {
            result += countMonoPoly(i, n-i);
            if (result > MAX) result %= MAX;
        }
        cout << result << endl;;
    }
}