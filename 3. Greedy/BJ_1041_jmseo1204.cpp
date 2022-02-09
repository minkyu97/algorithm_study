#include <bits/stdc++.h>
using namespace std;
using VI = vector<int>;
int main(){
    long long N;
    cin >> N;
    VI arr(6);
    int maxx=0;
    int sum=0;
    for(int& i : arr){
        cin >> i;
        maxx = max(maxx, i);
        sum+=i;
        }
   
    if(N==1) {
        cout << sum-maxx;
        return 0;
        }
    int m1 = min(arr[0], arr[5]);
    int m2 = min(arr[1], arr[4]);
    int m3 = min(arr[2], arr[3]);
    int min1 = min(m1, min(m2, m3));
    int max1 = max(m1, max(m2, m3));
    long long ret = (5*N-6)*(N-2)*min1+4*(2*N-3)*(m1+m2+m3-max1)+4*(m1+m2+m3);
    cout << ret;
    return 0;
    }
