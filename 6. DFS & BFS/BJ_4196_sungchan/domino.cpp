#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 100001;
int T, N, M;
int cnt, dfsn[MAX], SN, sn[MAX];
vector<int> adj[MAX];
bool finished[MAX];
stack<int> S;

int DFS(int curr) {
    dfsn[curr] = ++cnt;
    S.push(curr);

    int result = dfsn[curr];
    for(int next : adj[curr]) {
        if(dfsn[next] == 0) result = min(result, DFS(next));
        else if(!finished[next]) result = min(result, dfsn[next]);
    }

    if(result == dfsn[curr]) {
        while(true) {
            int t = S.top();
            S.pop();
            finished[t] = true;
            sn[t] = SN;
            if(t == curr) break;
        }
        SN++;
    }
    return result;
}

int main() {
    cin >> T;
    while(T--) {
        cin >> N >> M;
        cnt = SN = 0;
        for(int i = 1; i <= N; i++) {
            dfsn[i] = sn[i] = 0;
            adj[i].clear();
            finished[i] = false;
        }

        int x, y;
        for(int i = 0; i < M; i++) {
            cin >> x >> y;
            adj[x].push_back(y);
        }
        for(int i = 1; i <= N; i++) {
            if(dfsn[i] == 0) DFS(i);
        }

        vector<int> indegree(SN, 0);
        for(int i = 1; i <= N; i++) {
            for(int j: adj[i]) {
                if(sn[i] != sn[j]) {
                    indegree[sn[j]]++;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < SN; i++) {
            if(indegree[i] == 0) ans++;
        }
        cout << ans << endl;
    }
}