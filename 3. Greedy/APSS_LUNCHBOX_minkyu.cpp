#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define endl '\n'

using namespace std;
int C, N;

struct LunchBox {
    int warm;
    int eat;
};
vector<LunchBox> lunchBoxes;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> C;
    while(C--) {
        cin >> N;
        lunchBoxes = vector<LunchBox>(N);
        for (int i = 0; i < N; i++) cin >> lunchBoxes[i].warm;
        for (int i = 0; i < N; i++) cin >> lunchBoxes[i].eat;
        sort(lunchBoxes.begin(), lunchBoxes.end(), [](LunchBox a, LunchBox b) {return a.eat > b.eat;});
        int time = 0;
        int final_time = 0;
        for (LunchBox lb: lunchBoxes) {
            time += lb.warm;
            final_time = max(final_time, time + lb.eat);
        }
        cout << final_time << endl;
    }
}