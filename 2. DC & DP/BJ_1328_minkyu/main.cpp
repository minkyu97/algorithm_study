#include <iostream>
#include <vector>
#define endl '\n'
#define MAX 1000000007

using namespace std;
using ll = long long;
using matrix = vector<vector<ll> >;
using mat3d = vector<matrix>;

int N, L, R;
mat3d cache;
ll usingcache = 0;
ll calculate = 0;

ll solve(int N, int L, int R) {
    if (L > R) return solve(N, R, L);
    if (N==2) {
        if (L==2 && R==1) return 1;
        else if (L==1 && R==2) return 1;
        else return 0;
    }
    if (L == 0 || R == 0) return 0;
    ll& ret = cache[N][L][R];
    if(ret != -1) {
        usingcache++;
        return ret;
    }
    calculate++;
    ret = solve(N-1, L, R) * (N-2) + solve(N-1, L-1, R) + solve(N-1, L ,R-1);
    if (ret > MAX) ret %= MAX;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> L >> R;
    if (N==1) {
        cout << 1 << endl;
        return 0;
    }
    // 이 부분 중요!! 캐시를 0으로 초기화시키면 안 됨!! solve의 결과값이 0인 경우가 매우 많기 때문
    cache = mat3d(N+1, matrix(N+1, vector<ll>(N+1, -1)));
    cout << solve(N, L, R) << endl;
}