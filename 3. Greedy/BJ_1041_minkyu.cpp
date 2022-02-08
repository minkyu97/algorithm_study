#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef unsigned long long ll;

ll N;
ll dice[6];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < 6; i++) {
        cin >> dice[i];

    }
    ll mini = 1e9;
    ll maxi = 0;
    ll sum = 0;
    for (int i = 0; i < 6; i++) {
        sum += dice[i];
        mini = min(mini, dice[i]);
        maxi = max(maxi, dice[i]);
    }
    if (N==1) {
        cout << sum-maxi << endl;
        return 0;
    }
    ll mini2 = 1e9;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (i + j == 5 || i == j) continue;
            mini2 = min(mini2, dice[i] + dice[j]);
        }
    }
    ll mini3 = 1e9;
    mini3 = min(min(min(dice[0]+dice[1]+dice[2], dice[0]+dice[1]+dice[3]), 
                    min(dice[0]+dice[2]+dice[4], dice[0]+dice[3]+dice[4])), 
                min(min(dice[1]+dice[2]+dice[5], dice[1]+dice[3]+dice[5]), 
                    min(dice[2]+dice[4]+dice[5], dice[3]+dice[4]+dice[5])));

    ll result = mini * ((N-2)*4*(N-1)+(N-2)*(N-2)) + mini2 * (8*N-12) + mini3 * 4;
    cout << result << endl;
}