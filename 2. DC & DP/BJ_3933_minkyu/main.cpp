#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;
using matrix = vector<vector<int> >;
using mat3d = vector<matrix>;

int n;
vector<int> square;

// n을 m개의 제곱수로 쪼갤 수 있는 방법
int Lagrange(int n, int m, int start) {
    if (m == 0 && n == 0) return 1;
    if (m == 0 || n == 0) return 0;
    int ret = 0;
    for (int i = start; square[i] <= n; i++) {
        ret += Lagrange(n-square[i], m-1, i);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    while(cin >> n) {
        if (n == 0) break;
        for (int i = square.size(); true; i++) {
            int isquare = i*i;
            square.push_back(isquare);
            if (isquare > n) {
                break;
            }
        }
        cout << Lagrange(n, 4, 0) << endl;
    }
}