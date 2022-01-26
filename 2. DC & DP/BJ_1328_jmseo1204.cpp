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
template<typename T>
T abs(T a){
    return a > 0 ? a : -a;
}
int bitCount(uint bit){
    int cnt = 0;
    while(bit){
        cnt += bit & 1;
        bit >>= 1;
    }
    return cnt;
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

int factorial(VI& factorialDP, int a){
    if(a<0) return 0;
    else if(a==0) return 1;
    int& ret = factorialDP[a];
    if(ret!=-1) return ret;
    return ret= (ll)a * factorial(factorialDP, a-1)%MOD;
}
int bino(matrix<int>& dp, int N, int i){
    //cout << "inBINO : "<<N << ", "<<i <<endl;
    int& ret = dp[N][i];
    if(ret!=-1) return ret;
    else if(N==i || i==0) return 1;
    else if(N<i || i<0) return 0; //error
    else return ret=(bino(dp, N-1, i-1)+bino(dp, N-1, i))%MOD;
}

int recur(matrix<int>&dp, VI& factorialDP, matrix<int>& binoDP, int N, int L){
    //cout << "N : "<<N << ", L : "<< L << endl;
    if(N<L) return 0;
    else if(N==L) return 1;
    else if(L==0) return 0;
    int& ret = dp[N][L];
    if(ret!=-1) return ret;
    ll sum=0;
    for(int i=0; i<=N-1; i++){
        sum+=(ll)recur(dp, factorialDP, binoDP, i, L-1)*factorial(factorialDP, N-1-i)%MOD*bino(binoDP, N-1, i)%MOD;
    }
    //cout << N<<L<<" : "<<sum<<endl;
    return ret=sum%MOD;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N, L, R;
    cin >> N >> L >> R;
    matrix<int> dp(N, VI(N, -1));
    matrix<int> binoDP(N+1, VI(N+1, -1));
    VI fDP(N+1, -1);
    ll sum=0;
    for(int i=0; i<=N-1; i++){
        sum+=(ll)recur(dp, fDP, binoDP, i, L-1)*recur(dp, fDP, binoDP, N-1-i, R-1)%MOD*bino(binoDP, N-1, i)%MOD;
        sum%=MOD;
    }
    cout << sum;
    return 0;
}
