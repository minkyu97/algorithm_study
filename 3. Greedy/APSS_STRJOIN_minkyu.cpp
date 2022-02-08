#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#define endl '\n'

using namespace std;
int C, N;

int pop(priority_queue<int, vector<int>, greater<int> >& str) {
    int ret = str.top();
    str.pop();
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> C;
    while(C--) {
        cin >> N;
        priority_queue<int, vector<int>, greater<int> > str;
        while (N--) {
            int len;
            cin >> len;
            str.push(len);
        }
        int time = 0;
        while (str.size() > 1) {
            int a = pop(str);
            a += pop(str);
            time += a;
            str.push(a);
        }
        cout << time << endl;
    }
}