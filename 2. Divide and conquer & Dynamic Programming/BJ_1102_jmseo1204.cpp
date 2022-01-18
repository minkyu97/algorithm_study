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



#define INF 987654321
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


int bitCount(uint bit){
    int cnt = 0;
    while(bit){
        cnt += bit & 1;
        bit >>= 1;
    }
    return cnt;
}

int DFS(matrix& adj, unordered_map<uint, int>& dp, vi dist, uint travel, uint p, int end){
    //cout << "p : "<< p << endl;
    if(dp.count(travel)) return dp[travel];
    int N = adj.size();
    if(end <= bitCount(travel)){
        //cout <<"END" <<endl;
        dp[travel] = 0;
        return dp[travel];
    }
    int cost = INF;
    vi beforeDist(N);
    for(int j=0; j<N; j++){
        if(travel & 1 << j) continue;
        beforeDist[j] = dist[j];
        dist[j] = Min(dist[j], adj[p][j]);
    }
    for(int j=0; j<N; j++){
        if(travel & 1 << j) continue;
        cost = Min(cost, dist[j] + DFS(adj, dp, dist, travel | 1<<j, j, end));
    }

    
    dp[travel] = cost;
    return dp[travel];
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    matrix adj(N, vi(N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> adj[i][j];
        }
    }
    string onoff;
    cin >> onoff;
    int end;
    cin >> end;
    uint travel = 0;
    for(int i=0; i<N; i++){
        travel |= (onoff[i] == 'Y') << i;
    }
    vi dist(N, INF);
    
    unordered_map<uint, int> dp;

    for(int i=0; i<N; i++){
        if(!(travel & 1<<i)) continue;
        for(int j=0; j<N; j++){
            if(travel & 1<<j) continue;
            dist[j] = Min(dist[j], adj[i][j]);
        }
    }

    if(!(travel & -travel)) {
        if(end > 0){
            cout << -1;
        }else{
            cout << 0;
        }
        return 0;
    }
    int cost = DFS(adj, dp, dist, travel, (uint)log2(travel & -travel) , end);

    cout << cost;

    return 0;
}

