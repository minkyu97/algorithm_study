#include<iostream>
#include<vector>
#include<list>
#include<array>
#include<string>
#include<map>
#include<set>
#include<unordered_set>
#include<stack>
#include<queue>
#include<algorithm>
#include<math.h>
#include<bitset>
//#include<windows.h>
#include<ctime>
#include <bits/stdc++.h>



#define INF 1000000001
#define MIN 1e-10
#define HASHNUM 37813

using namespace std;
using ll = unsigned long long;
using matrix = vector<vector<int> >;
using uint = unsigned int;
using vi = vector<int>;
using vll = vector<ll>;
using two = pair<int, int>;

#define intA 65
#define MOD 1000000007



int Max(int a, int b){
    return a>b ? a : b;
}
int Min(int a, int b){
    return a>b ? b : a;
}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<two> edge(M);
    vector<int> dist(N+1, 1);

    for(int i=0; i<M; i++){
        cin >> edge[i].first >> edge[i].second;
    }
    sort(edge.begin(), edge.end(), [](two& a, two& b){return a.first < b.first;});
    for(int i=0; i<M; i++){
        int u = edge[i].first;
        int v = edge[i].second;
        dist[v] = Max(dist[v], dist[u]+1);
    }
    for(int i=1; i<=N; i++){
        cout << dist[i] << ' ';
    }

    




    return 0;
}

