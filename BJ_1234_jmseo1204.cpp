#include<bits/stdc++.h>
//#include<windows.h>
#define INF 987654321
#define MIN 1e-10
#define HASHNUM 37813
#define endl '\n'
#define intA 65
#define MOD 100000007
using namespace std;
using ll = long long;
template<typename T>
using matrix = vector<vector<T> >;
template<typename T>
using cube = vector<matrix<T> >;
using uint = unsigned int;
using VI = vector<int>;
using VLL = vector<ll>;
using P = pair<int, int>;
using PLL = pair<ll, ll>;
using VPLL = vector<PLL>;
using VP = vector<pair<int, int> >;
template<typename T1, typename T2, typename T3>
class three{
public:
    T1 a;
    T2 b;
    T3 c;
    three(T1&& x, T2&& y, T3&& z){
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
istream& operator >>(istream& is, three<T1, T2, T3>& p) {
    return is >> p.a >> p.b >> p.c;
}
template<typename T1, typename T2, typename T3, typename T4>
class four{
public:
    T1 a;
    T2 b;
    T3 c;
    T4 d;
    four(T1 x, T2 y, T3 z, T4 w){
        a=x;
        b=y;
        c=z;
        d=w;
    }
    four(){
        a= 0;
        b= 0;
        c= 0;
        d= 0;
    }
};
using F = four<int, int, int, int>;
using VF = vector<F>;
template<typename T1, typename T2, typename T3, typename T4>
ostream& operator <<(ostream& os, four<T1, T2, T3, T4>& p){
    return os << "(" << p.a <<" "<<p.b << " " << p.c<< " " << p.d<< ")";
}
template<typename T1, typename T2, typename T3, typename T4>
istream& operator >>(istream& is, four<T1, T2, T3, T4>& p){
    return is >> p.a >> p.b >> p.c >> p.d;
}
template<typename T>
ostream& operator<<(ostream& os, pair<T, T>& a){
    return os << "("<<a.first<<", "<<a.second<<")";
}
template<typename T>
istream& operator>>(istream& is, pair<T, T>& a){
    return is >> a.first >> a.second;
}
template<typename T>
ostream& operator <<(ostream& os, matrix<T>& arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[0].size(); j++){
            os << arr[i][j]<<' ';
        }
        os << endl;
    }
    return os;
}
template<typename T>
istream& operator >>(istream& is, matrix<T>& arr){
    for(int i=0; i<arr.size(); i++)
        for(int j=0; j<arr[0].size(); j++)
            is >> arr[i][j];
    return is;
}
template<typename T>
ostream& operator <<(ostream& os, vector<T>& arr){
    for(int i=0; i<arr.size(); i++) os << arr[i]<<' ';
    return os << endl;
}
template<typename T>
istream& operator >>(istream& is, vector<T>& arr){
    for(int i=0; i<arr.size(); i++) is >> arr[i];
    return is;
}
template<typename T>
ostream& operator << (ostream& os, list<T>& arr){
    for(auto i : arr){
        os << i << ' ';
    }
    return os;
}
int ulim(int a, int bound){
    return a>bound ? bound : a;
}

template<class T>
double abs(pair<T, T> a){return sqrt(pow(a.first, 2)+pow(a.second, 2));}

template<typename T>
ostream& operator << (ostream& os, stack<T>& arr){
    while(!arr.empty()){
        auto i = arr.top();
        arr.pop();
        os << i << ' ';
    }
    return os;
}




int bitCount(uint a){
    int ret = 0;
    while(a>0){
        ret += a&1;
        a >>= 1;
    }
    return ret;
}

ll getDP(cube<ll>& dp, int a, int b, int c){
    if(a<0 || b<0 || c<0) return 0;
    return dp[a][b][c];
}
void setDP(cube<ll>& dp, int a, int b, int c, int v){
    int A = dp.size();
    int B = dp[0].size();
    int C = dp[0][0].size();
    if(a>=A || b>=B || c>=C) return;
    dp[a][b][c] = v;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<cube<ll> > dp(2, cube<ll>(A+1, matrix<ll>(B+1, VLL(C+1, 3))));
    matrix<ll>bino(N+1, VLL(N+1));
    for(int i=0; i<=N; i++){
        for(int j=0; j<=i; j++){
            bino[i][j] = j==0 ? 1 : bino[i-1][j-1]+bino[i-1][j];
        }
    }


    setDP(dp[1], 0, 0, 0, 0);
    for(int i=1; i<=A; i++) setDP(dp[1], i, 0, 0, 1);
    for(int i=1; i<=B; i++) setDP(dp[1], 0, i, 0, 1);
    for(int i=1; i<=C; i++) setDP(dp[1], 0, 0, i, 1);

    for(int i=1; i<=A; i++) for(int j=1; j<=B; j++) setDP(dp[1], i, j, 0, 2);
    for(int i=1; i<=B; i++) for(int j=1; j<=C; j++) setDP(dp[1], 0, i, j, 2);
    for(int i=1; i<=C; i++) for(int j=1; j<=A; j++) setDP(dp[1], j, 0, i, 2);

    for(int i=2; i<=N; i++){
        for(int a=0; a<=A; a++){
            for(int b=0; b<=B; b++){
                for(int c=0; c<=C; c++){
                    dp[i%2][a][b][c]=getDP(dp[(i-1)%2], a-i, b, c)+getDP(dp[(i-1)%2], a, b-i, c)+getDP(dp[(i-1)%2], a, b, c-i);
                    if(i%2==0){
                        ll rate = bino[i][i/2];
                        dp[i%2][a][b][c]+=rate*getDP(dp[(i-1)%2], a-i/2, b-i/2, c);
                        dp[i%2][a][b][c]+=rate*getDP(dp[(i-1)%2], a, b-i/2, c-i/2);
                        dp[i%2][a][b][c]+=rate*getDP(dp[(i-1)%2], a-i/2, b, c-i/2);
                    }
                    if(i%3==0){
                        ll rate = bino[i][i/3]*bino[i*2/3][i/3];
                        dp[i%2][a][b][c]+=rate*getDP(dp[(i-1)%2], a-i/3, b-i/3, c-i/3);
                    }
                }
            }
        }
    }
    cout << dp[N%2][A][B][C];
}

