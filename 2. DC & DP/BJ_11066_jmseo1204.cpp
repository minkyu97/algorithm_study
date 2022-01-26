#include<bits/stdc++.h>
//#include<windows.h>
#define INF 987654321
#define MIN 1e-10
#define HASHNUM 37813
#define endl '\n'
#define intA 65
#define MOD 10000000
using namespace std;
using ll = unsigned long long;
template<typename T>
using matrix = vector<vector<T> >;
using uint = unsigned int;
using VI = vector<int>;
using VLL = vector<ll>;
using P = pair<int, int>;
using VP = vector<pair<int, int> >;

int Min(int a, int b){return a > b ? b : a;}

int merge(VI& arr, VI& psum, matrix<int>& dp, int s, int e){
    int& ret = dp[s][e];
    if(ret!=INF) return ret;
    for(int i=s; i<e; i++){
        ret = Min(ret, merge(arr, psum, dp, s, i)+merge(arr, psum, dp, i+1, e)+psum[e]-psum[s-1]);
    }
    return ret;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        int N;
        cin >> N;
        VI arr(N+1);
        VI psum(N+1);
        matrix<int> dp(N+1, VI(N+1, INF));
        for(int i=1; i<=N; i++){
            cin >> arr[i];
            dp[i][i] = 0;
            psum[i] = psum[i-1] + arr[i];
        }
        cout << merge(arr, psum, dp, 1, N) << endl;
    }
    return 0;
}


