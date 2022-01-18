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
#include<math.h>
#include<bitset>
//#include<windows.h>
#include<ctime>
#include <bits/stdc++.h>



#define INF 1000000001
#define MIN 1e-10
#define HASHNUM 37813

using namespace std;
using ll = unsigned long long;
using matrix = vector<vector<int> >;
using uint = unsigned int;
using vi = vector<int>;
using vll = vector<ll>;
using two = pair<int, int>;

#define intA 65
#define MOD 1000000007



int Max(int a, int b){
    return a>b ? a : b;
}
int Min(int a, int b){
    return a>b ? b : a;
}

void show(const vector<two>& arr){
    for(auto i : arr){
        cout << "("<<i.first <<", "<<i.second <<")" << " ";
    }
    cout << endl;
}

void show(const two& p){
    cout << "p : "<<p.first << ", "<< p.second << endl;
}

struct space{
    int xs;
    int xe;
    int ys;
    int ye;
    space(int _xs, int _xe, int _ys, int _ye){
        xs= _xs;
        xe= _xe;
        ys= _ys;
        ye= _ye;
    }
    space(){}
};

bool inSpace(const two& p, const space& board){
    return board.xs<=p.first && p.first<=board.xe && board.ys<=p.second && p.second<=board.ye;
}

bool checkPossibility(vector<two>& jam, vector<two>& impurity, int axis, int now, const space& board){
    int low_jam = 0;
    int high_jam = 0;
    int low_impurity = 0;
    int high_impurity = 0;
    //char axis = impurity[now].first;
    const two& p = impurity[now];
    //if(!inSpace(p, board)) return false;
    for(auto i : jam){
        if(!inSpace(i, board)) continue;
        if(axis == 1){
            if(i.second == p.second) return false; 
            if(i.second < p.second) low_jam++;
            else high_jam++;
        }else{
            if(i.first == p.first) return false; 
            if(i.first < p.first) low_jam++;
            else high_jam++;
        }
    }
    for(auto i : impurity){
        if(axis==1){
            if(i.second == p.second) continue; 
            if(i.second < p.second) low_impurity++;
            else high_impurity++;
        }else{
            if(i.first == p.first) continue; 
            if(i.first < p.first) low_impurity++;
            else high_impurity++;
        }
    }
    if(low_jam-low_impurity == 1 && high_jam - high_impurity ==1 ) return true;
    return false;
}

int recur(vector<two>& jam, vector<two>& impurity, int axis, int now, const space& board){
    const two& p = impurity[now];
    /*
    if(impurity.size()==0) {
        cout << "FINAL END at ";
        show(p);
        cout << "return : 1" << endl <<endl;
        return 1;
    }
    */
    space lowB;
    space highB;
    vector<two> low_impurity;
    vector<two> high_impurity;
    if(axis==1){
        lowB = *new space(board.xs, board.xe, board.ys, p.second-1);
        highB = *new space(board.xs, board.xe, p.second+1, board.ye);
    }else{
        lowB = *new space(board.xs, p.first-1, board.ys, board.ye);
        highB = *new space(p.first+1, board.xe, board.ys, board.ye);
    }
    for(auto i : impurity){
        if(inSpace(i, lowB)){
            low_impurity.push_back(i);
        }else if(inSpace(i, highB)){
            high_impurity.push_back(i);
        }
    }
    /*
    show(p);
    if(axis==1) cout << "|" <<endl;
    else cout << "--" << endl;
    cout << "low_impurity" << endl;
    show(low_impurity);
    cout << "high_impurity" << endl;
    show(high_impurity);
    */

    int lowsum = low_impurity.size() == 0 ? 1 : 0;
    int highsum = high_impurity.size() == 0 ? 1 : 0;

    for(int i=0; i<low_impurity.size(); i++){
        if(checkPossibility(jam, low_impurity, -axis, i, lowB)) lowsum+=recur(jam, low_impurity, -axis, i, lowB);
    }
    
    for(int i=0; i<high_impurity.size(); i++){
        if(checkPossibility(jam, high_impurity, -axis, i, highB)) highsum+=recur(jam, high_impurity, -axis, i, highB);
    }
    /*
    cout << "END at ";
    show(p);
    cout << "return : " <<lowsum*highsum<< endl << endl;
    */
    return lowsum*highsum;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N;
    matrix arr(N, vi(N));
    vector<two> impurity;
    vector<two> jam;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int temp;
            cin >> temp;
            if(temp==1) impurity.push_back({i, j});
            else if(temp==2) jam.push_back({i, j});
        }
    }
    vector<pair<int, int> > candid;
    space board(0, N-1, 0, N-1);
    for(int i=0; i<impurity.size(); i++){
        if(checkPossibility(jam, impurity, 1, i, board)) candid.push_back({1, i});
        if(checkPossibility(jam, impurity, -1, i, board)) candid.push_back({-1, i});
    }
    int sum=0;


    for(auto i : candid){
        //cout << "new start" <<endl;
        sum+=recur(jam, impurity, i.first, i.second, board);
    }

    if(sum==0) cout << -1;
    else cout << sum;




    return 0;
}

