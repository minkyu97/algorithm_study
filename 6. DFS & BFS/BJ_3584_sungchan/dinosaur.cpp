#include <iostream>
#include <vector>
using namespace std;
int T, N;

int main() {
    cin >> T;
    while(T--) {
        int ans = 0;
        cin >> N;
        vector<int> parent(N+1, 0);
        int A, B;
        for(int i = 0; i < N-1; i++) {
            cin >> A >> B;
            parent[B] = A;
        }
        cin >> A >> B;
        if(A == B || parent[A] == 0) ans = A;
        else if(parent[B] == 0) ans = B;
        else {
            vector<int> parents;
            parents.push_back(A);
            while(parent[A] != 0) {
                A = parent[A];
                parents.push_back(A);
            }
            bool done = false;
            while(!done) {
                for(int i : parents) {
                    if(B == i) {
                        ans = B;
                        done = true;
                        break;
                    }
                }
                B = parent[B];
            }
        }
        cout << ans << endl;
    }
}