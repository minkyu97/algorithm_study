#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int C, N, S;
int input;
vector<vector<int> > avg (100, vector<int>(100, 0));
// solved[i][j][s] i~j번째의 숫자들을 s개로 쪼갤 때 최소 편차 제곱의 합
vector<vector<vector<int> > > solved (100, vector<vector<int> >(100, vector<int>(100, 0)));

vector<int> numbers;

int getMinSquaredSum(int start) {

}

int solve(int start, int solvenum) {

    int ret = 0;
    for (int i = start; i < N - S + solvenum + 1; i++) {
        if (solved[start][0]) {
            // solved[start][solved] = 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> C;
    for (int i = 0; i < C; i++) {
        cin >> N >> S;
        for (int j = 0; j < N; j++) {
            cin >> input;
            numbers.push_back(input);
        }
        sort(numbers.begin(), numbers.end());
        cout << solve(0, 0) << endl;
    }
}