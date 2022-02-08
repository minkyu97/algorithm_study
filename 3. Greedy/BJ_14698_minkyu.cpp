#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef unsigned long long ll;

ll MAX = 1e9+7;
int T, N;
priority_queue<ll, vector<ll>, greater<ll> > slime;
ll cost;

ll pop(priority_queue<ll, vector<ll>, greater<ll> >& slime) {
    ll ret = slime.top();
    slime.pop();
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    while(T--) {
        cin >> N;
        slime = priority_queue<ll, vector<ll>, greater<ll> >();
        cost = 1;
        for (int i = 0; i < N; i++) {
            ll j;
            cin >> j;
            slime.push(j);
        }
        for (int i = 1; i < N; i++) {
            ll a = pop(slime);
            a *= pop(slime);
            cost *= (a % MAX);
            if (cost >= MAX) cost %= MAX;
            slime.push(a);
        }
        cout << cost << endl;
    }
    return 0;
}