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
    int N, M;
    cin >> N >> M;
    matrix<bool> adj(N, vector<bool>(N));
    disjoint_set ds(N);
    VI ret(N);
    int cnt = M-(N-1);
    for(int i=0; i<N; i++){
        string temp;
        cin >> temp;
        for(int j=i; j<N; j++) {
            adj[i][j] = temp[j]=='Y';
            if(adj[i][j]){
                if(ds.merge(i, j)){
                    ret[i]++;
                    ret[j]++;
                    adj[i][j] = false;
                }
            }
        }
    }
    if(!ds.isComplete()){
        cout << -1;
    }else{
        for(int i=0; i<N; i++){
            for(int j=i; j<N; j++) {
                if(adj[i][j] && cnt>0){
                    ret[i]++;
                    ret[j]++;
                    cnt--;
                }
            }
        }
        if(cnt!=0) {
            cout << -1;
        }else{
            for(int i : ret) cout << i <<' ';
        }
    }

}

