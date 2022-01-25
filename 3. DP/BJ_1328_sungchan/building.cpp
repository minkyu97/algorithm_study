#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
ll com[100][100];
ll fact[100];
ll cache[100][100];

void combination(int num) {
    if(num > 1) combination(num - 1);
    else {
        com[1][0] = com[1][1] = 1;
        return;
    }
    com[num][0] = 1;
    for(int i = 1; i <= num; i++) {
        com[num][i] = (com[num-1][i] + com[num-1][i-1]) % MOD;
    }
}

void factorial(int num) {
    if(num > 0) factorial(num - 1);
    else {
        fact[0] = 1;
        return;
    }
    fact[num] = (fact[num-1] * num) % MOD;
}

ll counter(int a, int b) {
    ll& ret = cache[a][b];
    if(ret != -1) return ret;

    if(b == 1) return ret = fact[a-1];
    if(a == b) return ret = 1;

    ll ans = 0;
    for(int i = b-1; i < a; i++) {
        ans += (com[a-1][i] * (counter(i, b-1) * fact[a-i-1] % MOD)) % MOD;
    }
    return ret = ans % MOD;
}

ll count(int n, int l, int r) {
    if(l + r > n + 1) return 0;
    if(n == 1) return 1;
    if(l == 1 && r == 1) return 0;

    combination(n-1);
    factorial(n-1);

    for(int i = 1; i < n; i++)
        for(int j = 1; j < n; j++)
            cache[i][j] = -1;

    if(l == 1 || r == 1) return counter(n-1, max(l, r)-1);

    ll ans = 0;
    for(int i = l - 1; i <= n - r; i++) {
        ans += (com[n-1][i] * (counter(i, l-1) * counter(n-i-1, r-1) % MOD)) % MOD;
    }
    return ans % MOD;
}

int main() {
    int N, L, R;
    cin >> N >> L >> R;
    cout << count(N, L, R) << endl;
}