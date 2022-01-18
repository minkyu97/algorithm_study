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


#define STAR 42;

using namespace std;


void dnc(int** arr, int s, int e, int r, int c){
    if(r==3 && c==5){
        arr[s][e+2] = STAR;
        arr[s+1][e+1] = STAR;
        arr[s+1][e+3] = STAR;
        arr[s+2][e] = STAR;
        arr[s+2][e+1] = STAR;
        arr[s+2][e+2] = STAR;
        arr[s+2][e+3] = STAR;
        arr[s+2][e+4] = STAR;
        return;
    }
    dnc(arr, s, e+c/2/2+1, r/2, c/2);
    dnc(arr, s+r/2, e, r/2, c/2);
    dnc(arr, s+r/2, e+c/2+1, r/2, c/2);

    return;
}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    

    
    int N;
    
    cin >> N;
    N=static_cast<int>(log2(N/3));
    int r=3, c=5;
    for(int i=0; i<N; i++){
        r*=2;
        c=2*c+1;
    }
    int** arr = new int*[r]();
    for(int i=0; i<r; i++){
        arr[i] = new int[c]();
    }
    //cout<<r<<endl;
    //cout<<c<<endl;
    dnc(arr, 0, 0, r, c);
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if (arr[i][j]==42) cout<<'*';
            else cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
