#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
int N;
priority_queue<int, vector<int>, greater<int> > card;

int pop(priority_queue<int, vector<int>, greater<int> >& str) {
    int ret = str.top();
    str.pop();
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    card = priority_queue<int, vector<int>, greater<int> >();
    while(N--) {
        int i;
        cin >> i;
        card.push(i);
    }
    int cost = 0;
    while(card.size() != 1) {
        int a = pop(card);
        a += pop(card);
        cost += a;
        card.push(a);
    }

    cout << cost << endl;
}