#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
int N, L, src, dst;
vector<list<int> > hosun;
vector<list<int> > jiha;
vector<bool> hosunSeen;
vector<bool> jihaSeen;

int pop(vector<int>& q) {
    int ret = q.back();
    q.pop_back();
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> L;
    hosun = vector<list<int> >(L+1);
    hosunSeen = vector<bool>(L+1, false);
    jiha = vector<list<int> >(N+1);
    jihaSeen = vector<bool>(N+1, false);

    for (int i = 0; i < L; ++i) {
        int j;
        cin >> j;
        while(j > 0) {
            hosun[i].push_back(j);
            jiha[j].push_back(i);
            cin >> j;
        }
    }

    cin >> src >> dst;

    int here = src;
    vector<int> q1;
    vector<int> q2;
    int minimumTransfer = 0;

    for(int e: jiha[here]) {
        q1.push_back(e);
    }

    for (; ; ++minimumTransfer) {
        if (q1.empty()) {
            cout << -1 << endl;
            return 0;
        }
        while(!q1.empty()) {
            int hosun_num = pop(q1);
            if (hosunSeen[hosun_num]) continue;
            for (int jiha_num: hosun[hosun_num]) {
                if (jihaSeen[jiha_num]) continue;
                if (jiha_num == dst) goto FINISH;
                q2.push_back(jiha_num);
            }
            hosunSeen[hosun_num] = true;
        }
        while(!q2.empty()) {
            here = pop(q2);
            if (jihaSeen[here]) continue;
            for(int e: jiha[here]) {
                if (hosunSeen[e]) continue;
                q1.push_back(e);
            }
            jihaSeen[here] = true;
        }
    }
    FINISH:
    cout << minimumTransfer << endl;
    return 0;
}