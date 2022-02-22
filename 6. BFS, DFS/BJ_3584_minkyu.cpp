#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int T, N;
vector<int> parentOf;
vector<bool> seen;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while(T--) {
        cin>> N;
        parentOf = vector<int>(N+1, 0);
        seen = vector<bool>(N+1, false);
        int parent, child;
        for (int i = 1; i < N; ++i) {
            cin >> parent >> child;
            parentOf[child] = parent;
        }
        int A, B;
        cin >> A >> B;
        parent = A;
        while (parent) {
            if (parent == B) {
                cout << parent << endl;
                goto FINISH;
            }
            seen[parent] = true;
            parent = parentOf[parent];
        }

        parent = B;
        while(parent) {
            if (seen[parent]) {
                cout << parent << endl;
                goto FINISH;
            }
            parent = parentOf[parent];
        }

        FINISH:
        continue;
    }
}