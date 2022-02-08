#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
int N, M;
vector<int> crane;
vector<int> allo;
vector<int> box;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    crane = vector<int>(N);
    allo = vector<int>(N, 0);
    for (int i = 0; i < N; i++) cin >> crane[i];
    sort(crane.rbegin(), crane.rend());
    cin >> M;
    box = vector<int>(M);
    for (int i = 0; i < M; i++) cin >> box[i];
    sort(box.rbegin(), box.rend());
    if (box.front() > crane.front()) {
        cout << -1 << endl;
        return 0;
    }
    for (vector<int>::iterator b = box.begin(); b != box.end(); b++) {
        for (int i = 0; i < N; i++) {
            if (i == N-1 || crane[i+1] < *b || allo[i] < allo[i+1]) {
                allo[i]++;
                break;
            }
        }
    }
    int a = 0;
    for (int i = 0; i < N; i++) {
        a = max(a, allo[i]);
    }
    cout << a << endl;

}