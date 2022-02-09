#include<bits/stdc++.h>
//#include<windows.h>
#define INF 1987654321
#define MIN 1e-10
#define endl '\n'
#define MOD 1000000007
#define ALL(x) begin(x),end(x)
using namespace std;
using ll = long long;
template<typename T>
using matrix = vector<vector<T> >;
template<typename T>
using cube = vector<matrix<T> >;
using uint = unsigned int;
using VI = vector<int>;
using VB = vector<bool>;
using VLL = vector<ll>;
using P = pair<int, int>;
using PLL = pair<ll, ll>;
using VPLL = vector<PLL>;
using VP = vector<pair<int, int> >;


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
    return os;
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


template<class T>
double abs(pair<T, T> a){return sqrt(pow(a.first, 2)+pow(a.second, 2));}
ll max(ll a, ll b){return a>b ? a : b;}


int main(){
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    priority_queue<int, VI, greater<int> > pq;
    VI ret(N-1);
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        pq.push(temp);
    }
    for(int i=0; i<N-1; i++){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ret[i] = a+b;
        pq.push(ret[i]);
    }
    cout << accumulate(ALL(ret), 0) << endl;
}

