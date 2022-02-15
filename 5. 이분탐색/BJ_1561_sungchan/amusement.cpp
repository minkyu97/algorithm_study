#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
int N, M;

int main() {
    cin >> N >> M;
    int* time = new int[M];
    for(int i = 0; i < M; i++) {
        cin >> time[i];
    }

    if(N <= M) {
        cout << N;
        return 0;
    }

    ll low = 0;
    ll high = 30 * (ll)(ceil((double) N / (double) M));
    ll mid = (low+high)/2;

    while(true) {
        ll cnt = M;
        for(int i = 0; i < M; i++) {
            cnt += mid / time[i];
            if(cnt >= N) break;
        }
        if(cnt >= N) high = mid;
        else if(cnt < N) low = mid;
        mid = (low+high)/2;
        if(low+1 == high && cnt < N) {
            mid = high;
            break;
        }
    }

    int cnt = M;
    for(int i = 0; i < M; i++) {
        cnt += (mid-1)/ time[i];
    }
    int num = N-cnt;
    int ans = -1;
    for(int i = 0; i < M; i++) {
        if(mid % time[i] == 0) {
            num--;
        }
        if(num == 0) {
            ans = i+1;
            break;
        }
    }

    cout << ans;
}