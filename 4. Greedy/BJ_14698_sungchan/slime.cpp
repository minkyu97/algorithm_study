#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int T, *N;
typedef unsigned long long ll;
ll MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    N = new int[T];
    ll *product = new ll[T];
    for(int i = 0; i < T; i++) {
        cin >> N[i];
        ll ener;
        priority_queue<ll, vector<ll>, greater<>> energy;
        for(int j = 0; j < N[i]; j++) {
            cin >> ener;
            energy.push(ener);
        }

        product[i] = 1;
        while(energy.size() > 1) {
            ll num1 = energy.top();
            energy.pop();
            ll num2 = energy.top();
            energy.pop();
            energy.push(num1 * num2);
            product[i] *= ((num1 % MOD) * (num2 % MOD)) % MOD;
            product[i] %= MOD;
        }
    }
    for(int i = 0; i < T; i++) {
        cout << product[i] << "\n";
    }
}