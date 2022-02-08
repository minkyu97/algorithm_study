#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int C, N, win;
vector<int> russia, korea;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> C;
    while(C--) {
        win = 0;
        cin >> N;
        russia = vector<int>(N);
        korea = vector<int>(N);
        for (int i = 0; i < N; i++) {
            cin >> russia[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> korea[i];
        }
        sort(russia.begin(), russia.end());
        sort(korea.begin(), korea.end());
        vector<int>::iterator k = korea.begin();
        for (vector<int>::iterator r = russia.begin(); r != russia.end(); r++) {
            TRYAGAIN:
            if (k == korea.end()) break;
            if (*k >= *r) {
                k++;
                win++;
            }
            else {
                k++;
                goto TRYAGAIN;
            }
        }
        cout << win << endl;
    }
}