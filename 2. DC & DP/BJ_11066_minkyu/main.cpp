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
matrix bound;
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
        bound = matrix(K+1, vector<int>(K+1));
        sum = vector<int>(K+1);
        for (int j = 1; j <= K; j++) {
            int a;
            cin >> a;
            cache[j][j] = 0;
            bound[j][j] = j;
            sum[j] = sum[j-1] + a;
        }
        for (int j = 2; j <= K; j++) {
            cache[j-1][j] = sum[j] - sum[j-2];
            bound[j-1][j] = j-1;
        }
        for (int diff = 2; diff < K; diff++) {
            for (int start = 1; start <= K - diff; start++) {
                int end = start+diff;
                for (int i = bound[start][end-1]; i <= bound[start+1][end]; i++) {
                    int temp = cache[start][i] + cache[i+1][end];
                    if (temp < cache[start][end]) {
                        cache[start][end] = temp;
                        bound[start][end] = i;
                    }
                }
                cache[start][end] += calcsum(start, end);
            }
        }
        
        cout << cache[1][K] << endl;
    }
}