#include <iostream>
#include <vector>
#include <cmath>
#define endl '\n'
#define MAX 987654321

using namespace std;

int n;
vector<int> square;

// n을 m개 이하의 제곱수로 쪼갤 수 있는 방법
int Lagrange(int n, int m, int start) {
    if (n == 0) return 1;
    if (m == 0) return 0;
    int ret = 0;
    // 중요!! 제곱수는 작은수부터 골라나갈 것이므로 n/m보다 클 수 없음
    for (int i = start; i != -1 && square[i] >= (n/m); i--) {
        ret += Lagrange(n-square[i], m-1, min(i,(int)(sqrt(n-square[i]))));
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
        cout << Lagrange(n, 4, sqrt(n)) << endl;
    }
}