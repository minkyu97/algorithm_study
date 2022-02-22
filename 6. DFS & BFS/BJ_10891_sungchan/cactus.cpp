#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;
const int MAX = 100001;
typedef pair<int, int> P;

int N, M, dcnt, dfsn[MAX];
vector<int> adj[MAX];
stack<P> S;
vector<vector<P>> bcc;

int DFS(int curr, int prev = -1) {
    int result = dfsn[curr] = ++dcnt;

    for(int next: adj[curr]) {
        if(next == prev) continue;
        if(dfsn[curr] > dfsn[next]) S.push(P(curr, next));
        if(dfsn[next] > 0) result = min(result, dfsn[next]);
        else {
            int temp = DFS(next, curr);
            result = min(result, temp);
            if(temp >= dfsn[curr]) {
                vector<P> currBCC;
                while(!S.empty() && S.top() != P(curr, next)) {
                    currBCC.push_back(S.top());
                    S.pop();
                }
                currBCC.push_back(S.top());
                S.pop();
                bcc.push_back(currBCC);
            }
        }
    }

    return result;
}

int main() {
    cin >> N >> M;
    int x, y;
    for(int i = 0; i < M; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 0; i < N; i++) {
        if(dfsn[i] == 0) DFS(i);
    }

    bool cactus = true;
    if(bcc.size() == 1) {
        if(M > N) cactus = false;
    }
    vector<bool> checked(N);
    for(auto &c: bcc) {
        if(c.size() == 1) continue;
        set<int> nodes;
        for(auto &p: c) {
            nodes.insert(p.first);
            nodes.insert(p.second);
        }
        for(int node: nodes) {
            if(checked[node]) cactus = false;
            checked[node] = true;
        }
        int n = nodes.size();
        int m = c.size();
        if(m > n) cactus = false;
    }

    if(cactus) cout << "Cactus";
    else cout << "Not cactus";
}