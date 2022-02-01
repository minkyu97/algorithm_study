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

int recur(matrix<int>& candid, string& str, int make, int p, int cnt){
    int num = stoi(str);
    if(p==str.size()) return make == 0 ? (1+num) : (abs(make-num)+cnt);
    VI& arr = candid[p];
    int min = abs(num-100);
    for(int i : arr){
        int ret = recur(candid, str, make*10+i, p+1, cnt+(i>9? 2 : 1));
        min = Min(min, ret);
    }
    if(p==0 && str.size()>1) min = Min(min, recur(candid, str, make, p+1, cnt));
    return min;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string N;
    cin >> N;
    int M;
    cin >> M;
    VI del(M);
    cin >> del;
    VI arr;
    for(int i=0; i<=9; i++){
        bool canPush = true;
        for(int j : del){
            if(i==j){
                canPush = false;
                break;
            }
        }
        if(canPush) arr.push_back(i);
    }

    int leng = N.length();
    if(arr.size()==0){
        cout << abs(stoi(N)-100);
        return 0;
    }else if (arr.front()==0 && arr.size()==1) {
        int num = stoi(N);
        cout << Min(abs(num-100), num+1);
        return 0;
    }


    int min = arr.front();
    matrix<int> candid(leng, arr);
    if(min == 0) candid[0].push_back(arr[1]*10);
    else candid[0].push_back(min*11);
    int cnt=0;
    int delta = recur(candid, N, 0, 0, cnt);
    cout << delta;

    return 0;
}


