#include <iostream>
#include <vector>
#include <cmath>
#define endl '\n'
#define MAX 987654321

using namespace std;

int n;
vector<int> square;
int cnt;

// n을 m개 이하의 제곱수로 쪼갤 수 있는 방법
int Lagrange(int n, int m, int start) {
    if (n == 0) return 1;
    if (m == 0) return 0;
    int ret = 0;
    // 중요!! 제곱수는 큰 수부터 골라나갈 것이므로 n/m보다 작을 수 없음
    // 그리고 꼭 큰 수부터 빼야됨.
    // for문의 범위를 보면 작은 수부터 뺐을 때는 0 ~ root(n/m)
    // 큰 수부터 뺐을 때는 root(n/m) ~ root(n)으로 범위제한을 하고 있는데,
    // 어느 쪽이건 n이 작으면 작을 수록 범위가 줄어드는 것을 알 수 있음
    // 큰 수부터 뺄 경우 재귀호출된 함수에서 for문의 범위가 급격하게 줄어들음
    for (int i = start; i != -1 && square[i] >= (n/m); i--) {
        ret += Lagrange(n-square[i], m-1, min(i,(int)(sqrt(n-square[i]))));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while(cin >> n) {
        if (n == 0) break;
        cnt = 0;
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