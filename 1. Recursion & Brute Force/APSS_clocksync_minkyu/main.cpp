#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max();

vector< vector<int> > switches {
    {0,1,2},
    {3,7,9,11},
    {4,10,14,15},
    {0,4,5,6,7},
    {6,7,8,10,12},
    {0,2,14,15},
    {3,14,15},
    {4,5,7,14,15},
    {1,2,3,4,5},
    {3,4,5,9,13},
};

int C, result;
vector<int> clocks(16);
int countPushing(vector<int> &clocks, int swi);
bool complete(vector<int> &clocks);

int main() {
    cin >> C;
    for(int i = 0; i < C; i++) {
        for(int j = 0; j < 16; j++) {
            cin >> clocks.at(j);
        }
        result = countPushing(clocks, 0);
        if (result > 30) {
            cout << -1 << endl;
        }
        else cout << countPushing(clocks, 0) << endl;
    }

    return 0;
}

// 현재 clocks 상태에서 번호가 swi 이상인 스위치들을 최소 몇 번 눌러서 정렬 시킬 수 있는지 반환
int countPushing(vector<int> &clocks, int swi) {
    vector<int> temp {0,1,2,3};
    
    if(swi == 10) {
        return 31;
    }


    // 현재 clocks 상태에서 swi를 i번 눌렀을 때의 clocks 상태에서 swi 이상의 스위치들을 최소 몇 번 눌러서 complete 시킬 수 있는지
    // -> 현재 complete 상태라면 i, 아니라면 i + countPushing(clocks, swi+1)
    
    for(int i = 0; i < 4; i++) {
        if(!complete(clocks)) {
            temp[i] = i + countPushing(clocks, swi+1);
        }
        for(int j: switches[swi]) {
            clocks[j] += 3;
        }
    }
    

    int min = INF;
    
    for(int i: temp) {
        if(i < min) min = i;
    }

    return min;
}

bool complete(vector<int> &clocks) {
    for(int i: clocks) {
        if(i % 12 != 0) return false;
    }
    return true;
}