#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int C, N;
vector<list<int> > G;
vector<int> inorder;
list<char> result;
int numAlpha;

int pop(list<int>& q) {
    int ret = q.back();
    q.pop_back();
    return ret;
}

bool toplogical() {
    list<int> q;
    for (int i = 0; i < 26; i++) {
        if (inorder[i] == 0) q.push_back(i);
    }
    while(q.size() > 0) {
        int here = pop(q);
        for (int there: G[here]) {
            if(--inorder[there] == 0) q.push_back(there);
        }
        result.push_back(here+'a');
        --numAlpha;
    }
    return numAlpha == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> C;
    while (C--) {
        G = vector<list<int> >(26);
        inorder = vector<int>(26, -1);
        result.clear();
        numAlpha = 0;

        cin >> N;
        string before;
        string now;
        cin >> before;

        while (--N) {
            cin >> now;
            int size = min(before.size(), now.size());
            for (int i = 0; i < size; i++) {
                if (before[i] != now[i]) {
                    int from = before[i] - 'a';
                    int to = now[i] - 'a';
                    G[from].push_back(to);
                    if (inorder[from] < 0) inorder[from] = 0;
                    if (inorder[to] < 0) {
                        inorder[to] = 1;
                    }
                    else ++inorder[to];
                    break;
                }
            }
            before = now;
        }

        for (int i = 0; i < 26; ++i) {
            if (inorder[i] < 0) {
                result.push_back(i+'a');
                continue;
            }
            ++numAlpha;
        }

        bool valid = toplogical();

        if (valid) {
            for (char c: result) cout << c;
            cout << endl;
            continue;
        } else {
            cout << "INVALID HYPOTHESIS" << endl;
            continue;
        }
        
    }    
}