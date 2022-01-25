#include<bits/stdc++.h>
//#include<windows.h>
#define INF 987654321
#define MIN 1e-10
#define HASHNUM 37813
#define endl '\n'
#define intA 65
#define MOD 1000000007
using namespace std;
using ll = unsigned long long;
template<typename T>
using matrix = vector<vector<T> >;
using uint = unsigned int;
using VI = vector<int>;
using VLL = vector<ll>;
using P = pair<int, int>;
using VP = vector<pair<int, int> >;
template<typename T1, typename T2, typename T3>
class three{
public:
    T1 a;
    T2 b;
    T3 c;
    three(T1& x, T2& y, T3& z){
        a=x;
        b=y;
        c=z;
    }
    three(){
        a= 0;
        b= 0;
        c= 0;
    }

};
using T = three<int, int, int>;
using VT = vector<T>;
template<typename T1, typename T2, typename T3>
ostream& operator <<(ostream& os, three<T1, T2, T3>& p){
    return os << "(" << p.a <<" "<<p.b << " " << p.c<< ")";
}
template<typename T1, typename T2, typename T3>
istream& operator >>(istream& is, three<T1, T2, T3>& p){
    return is >> p.a >> p.b >> p.c;
}
template<typename T>
T Max(T a, T b){
    return less<T>()(a, b) ? b : a;
}
template<typename T>
T Min(T a, T b){
    return less<T>()(a, b) ? a : b;
}


int ulim(int a, int bound){
    return a>bound ? bound : a;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N, M, K;
    cin >> N >> M >> K;
    VT arr(N+1);
    for(int i=1; i<=N; i++) cin >> arr[i];
    vector<matrix<int> > dp(2, matrix<int>(5*(N+2), VI(M+1, -1)));
    dp[0][0][0]=0;
    for(int i=1; i<=N; i++){
        for(int j=0; j<=5*i; j++){
            for(int k=0; k<=M; k++){
                if(dp[(i-1)%2][j][k]==-1) continue;
                int cpu = arr[i].a;
                int mem = arr[i].b;
                int cost = arr[i].c;
                dp[i%2][j][k] = Max(dp[i%2][j][k], dp[(i-1)%2][j][k]);
                int temp = Max(dp[(i-1)%2][j][k]+mem, dp[(i-1)%2][j+cost][ulim(k+cpu, M)]);
                dp[i%2][j+cost][ulim(k+cpu, M)]=Max(dp[i%2][j+cost][ulim(k+cpu, M)], temp);
            }
        }
        //cout << dp[i%2] << endl;
    }
    int ret = -1;
    for(int j=1; j<=5*N; j++){
        if(dp[N%2][j][M]>=K){
            ret = j;
            break;
        }
    }
    cout << ret;
    return 0;
}


