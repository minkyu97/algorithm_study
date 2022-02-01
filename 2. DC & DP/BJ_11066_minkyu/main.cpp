#include <iostream>
#include <vector>
#include <cmath>
#define endl '\n'
#define MAX 987654321

using namespace std;
using matrix = vector<vector<int> >;

int T, K;
// i번째부터 i+j번째 챕터를 합칠 수 있는 최소 비용 저장
matrix cache;
vector<int> sum;

// O(n)으로 줄일 수 있음
int calcsum(int start, int end) {
    return sum[end] - sum[start-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> K;
        cache = matrix(K+1, vector<int>(K+1, MAX));
        sum = vector<int>(K+1);
        for (int j = 1; j <= K; j++) {
            int a;
            cin >> a;
            cache[j][0] = 0;
            sum[j] = sum[j-1] + a;
        }
        for (int diff = 1; diff < K; diff++) {
            for (int start = 1; start <= K - diff; start++) {
                for (int i = 1; i <= diff; i++) {
                    cache[start][diff] = min(
                        cache[start][diff],
                        cache[start][i-1] + cache[start+i][diff-i]
                    );
                }
                cache[start][diff] += calcsum(start, start+diff);
            }
        }
        
        cout << cache[1][K-1] << endl;
    }
}