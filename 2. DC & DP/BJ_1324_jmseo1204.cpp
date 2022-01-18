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
#include<cmath>
#include<bitset>
//#include<windows.h>
#include<ctime>
#include<random>



#define INF 987654321
#define MIN 1e-10
#define HASHNUM 37813
#define endl '\n'

using namespace std;
using ll = unsigned long long;
using matrix = vector<vector<int> >;
using uint = unsigned int;
using vi = vector<int>;
using vll = vector<ll>;
using P = pair<int, int>;
using XY = vector<pair<int, int> >;

#define intA 65
#define MOD 1000000007


int Max(int a, int b){
    return a>b ? a : b;
}
int Min(int a, int b){
    return a>b ? b : a;
}
double Max(double a, double b){
    return a>b ? a : b;
}
double Min(double a, double b){
    return a>b ? b : a;
}



int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    vi arr(N+1);
    vector<vector<P> > dp(N+1, vector<P>(N+1, {0,0}));

    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    for(int i=1; i<=N; i++){
        int now;
        cin >> now;
        for(int j=1; j<=N; j++){
            if(arr[j]==now) {
                P temp1 = {0, INF};
                P temp2 = {0, INF};
                for(int k=1; k<=i; k++){
                    P u = dp[i-k][j];
                    if (u.second < now) {
                        u.first++;
                        u.second = now;
                        temp1 = comp(temp1, u);
                    }
                }
                for(int k=1; k<=j; k++){
                    P l = dp[i][j-k];
                    if (l.second < now) {
                        l.first++;
                        l.second = now;
                        temp2 = comp(temp2, l);
                    }
                }
                dp[i][j] = comp(temp1, temp2);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    //show(dp, true);
    int max = 0;
    for(int i=1; i<=N; i++){
        max = Max(max, dp[N][i].first);
    }
    cout << max;


    return 0;
}


