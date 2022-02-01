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


int main(){
    //cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int cnt = 0;
    while(true){
        int N;
        cin >> N;
        if(N==0) break;
        cnt++;
        matrix<int> arr(N);
        matrix<int> psum(N);
        cube<int> dp(2, matrix<int>(N, VI(2*N+1, -INF)));
        int M = -INF;
        for(int i=0; i<N; i++){
            arr[i] = *new VI(2*i+1);
            psum[i] = *new VI(2*i+2);
            for(int j=0; j<=2*i; j++){
                cin >> arr[i][j];
                M = max(M, arr[i][j]);
                dp[1][i][j] = arr[i][j];
                psum[i][j+1] = arr[i][j] + psum[i][j];
            }
        }
        for(int k=2; k<=N; k++){
            for(int i=0; i<N; i++){
                for(int j=0; j<=2*i; j++){
                    if(j%2==0 && i<N-(k-1)){
                        dp[k%2][i][j] = dp[(k-1)%2][i][j] + psum[i+k-1][j+2*k-1] - psum[i+k-1][j];
                        M = max(M, dp[k%2][i][j]);
                    }else if(j%2==1 && k<=N/2 && i>=2*k-1 && 2*k-1<=j && j<=2*i-(2*k-1)){
                        dp[k%2][i][j] = dp[(k-1)%2][i][j] + psum[i-(k-1)][j+1] - psum[i-(k-1)][j+1-(2*k-1)];
                        M = max(M, dp[k%2][i][j]);
                    }
                }
            }
        }
        cout <<cnt<<". "<<  M << endl;
    }
}

