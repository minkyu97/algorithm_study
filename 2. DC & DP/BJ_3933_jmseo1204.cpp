#include<bits/stdc++.h>
//#include<windows.h>
#define INF 987654321
#define MIN 1e-10
#define HASHNUM 37813
#define endl '\n'
#define intA 65
#define MOD 1000000007
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
using VP = vector<pair<int, int> >;

template<typename T>
T Min(T a, T b){
    return less<T>()(a, b) ? a : b;
}


int recur(int p, int bound, int cnt){
    if(p==0) return 1;
    else if(cnt==4) return 0;
    int ret = 0;
    for(int i=bound; i>=sqrt((double)p/(4-cnt)); i--){
        ret+=recur(p-i*i, Min(i, (int)sqrt(p-i*i)), cnt+1);
    }
    return ret;
}


int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while(true){
        int temp;
        cin >> temp;
        if(temp==0) break;
        cout << recur(temp, sqrt(temp), 0) << endl;
    }

    return 0;
}