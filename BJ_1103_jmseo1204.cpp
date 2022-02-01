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


int DFS(matrix<int>& arr, matrix<int>& dp, matrix<bool>& travel, int r, int c){
    int N = arr.size();
    int M = arr[0].size();
    if(r<0 || r>=N || c<0 || c>=M || arr[r][c]==0) return 0;
    else if(travel[r][c]) return INF;
    int& ret = dp[r][c];
    if(ret!=-1) return ret;
    travel[r][c] = true;
    int Max = 0;
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if((i+j+2)%2==0) continue;
            Max = max(Max, DFS(arr, dp, travel, r+i*arr[r][c], c+j*arr[r][c]));
        }
    }
    travel[r][c] = false;
    return ret = Max+1;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    matrix<int> arr(N, VI(M));
    matrix<bool> travel(N, vector<bool>(M));
    matrix<int> dp(N, VI(M, -1));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char temp;
            cin >> temp;
            arr[i][j] = temp == 'H' ? 0 : (temp -'0');
        }
    }
    int ret = DFS(arr, dp, travel, 0, 0);
    cout << (ret >= INF ? -1 : ret);

}


