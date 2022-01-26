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


matrix& division(unordered_map<ll, matrix>& dp, ll B){
    if(dp.count(B)) return dp[B];
    int N = dp[1].size();
    dp.insert({B/2*2, matrix(N, vi(N))});
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                dp[B/2*2][i][j] += division(dp, B/2)[i][k] * division(dp, B/2)[k][j];
                dp[B/2*2][i][j]%=1000;
            }
        }
    }
    if(B%2==1){
        dp.insert({B, matrix(N, vi(N))});
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                for(int k=0; k<N; k++){
                    dp[B][i][j] += dp[1][i][k] * dp[B-1][k][j];
                    dp[B][i][j]%=1000;
                }
            }
        }
    }
    return dp[B];
}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    ll B;
    cin >> N >> B;
    unordered_map<ll, matrix> dp;
    dp.insert({1, matrix(N, vi(N))});
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int temp;
            cin >> temp;
            dp[1][i][j] = temp%1000;
        }
    }
    division(dp, B);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << dp[B][i][j] << ' ';
        }
        cout << '\n';
    }




    return 0;
}

