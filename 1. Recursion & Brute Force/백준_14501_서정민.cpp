#include<iostream>
#include<vector>
#include<array>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<math.h>

#define INF 987654321

using namespace std;

#define HASHNUM 37813
#define MIN 1e-10

int max(int a, int b){
    return a>b ? a : b;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<pair<int, int> > input;
    input.push_back(*new pair<int, int>(0,0));
    for(int i=0; i<N; i++){
        int Ti, Pi;
        cin >> Ti >> Pi;

        input.push_back(*new pair<int, int>(Ti, Pi));
    }
    vector<int> cache(N+2, 0);
    for(int i=N; i>=1; i--){
        int Ti = input[i].first;
        int Pi = input[i].second;
        
        if(i+Ti-1>N){
            cache[i] = cache[i+1];
            continue; 
        }else{
            cache[i] = max(cache[i+Ti] + Pi, cache[i+1]);
        }
    }
    cout << cache[1];
   
    return 0;

}