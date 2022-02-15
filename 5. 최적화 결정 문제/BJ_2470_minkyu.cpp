#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int N;
vector<int> liquid;

bool decision(int sum) {

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    liquid = vector<int>(N);
    for (int i = 0; i < N; i++) cin >> liquid[i];

    sort(liquid.begin(), liquid.end());
    
    vector<int>::iterator i = liquid.begin(), j = liquid.end()-1;
    vector<int>::iterator left = liquid.begin(), right = liquid.end()-1;
    int gap = *i + *j;
    int mingap = abs(gap);
    while (i < j-1) {
        if (gap > 0) {
            j--;
            gap = *i + *j;
            if (mingap > abs(gap)) {
                mingap = abs(gap);
                left = i;
                right = j;
            }
        }
        else if (gap < 0) {
            i++;
            gap = *i + *j;
            if (mingap > abs(gap)) {
                mingap = abs(gap);
                left = i;
                right = j;
            }
        }
        else break;
    }
    cout << *left << ' ' << *right << endl;
}