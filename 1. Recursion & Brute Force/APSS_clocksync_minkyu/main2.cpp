#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max();
#define endl '\n'

vector< vector<int> > switch_clock {
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

vector< vector<int> > clock_switch {
    {0, 3, 5},          // 0번 시계
    {0, 8},             // 1번 시계
    {0, 5, 8},          // 2번 시계
    {1, 6, 8, 9},       // 3번 시계
    {2, 3, 7, 8, 9},    // 4번 시계
    {3, 7, 8, 9},       // 5번 시계
    {3, 4},             // 6번 시계
    {1, 3, 4, 7},       // 7번 시계
    {4},                // 8번 시계
    {1, 9},             // 9번 시계
    {2, 4},             // 10번 시계
    {1},                // 11번 시계
    {4},                // 12번 시계
    {9},                // 13번 시계
    {2, 5, 6, 7},       // 14번 시계
    {2, 5, 6, 7}        // 15번 시계
};

int C, temp, counts = 0;
vector<int> clocks(16);

bool complete(vector<int> &clocks) {
    for(int i: clocks) {
        if(i % 12 != 0) return false;
    }
    return true;
}

int* oneSwitchClock(vector< vector<int> > &clock_switch) {
    int* ret = new int[2] {1,2}; 
    for (int clock = 0; clock < 16; clock++) {
        if (clock_switch[clock].size() == 1) {
            ret[0] = clock;
            ret[1] = clock_switch[clock][0];
            return ret;
        }
    }
    cout << "wrong answer" << endl;
    return ret;
}

int main() {
    cin >> C;
    for(int i = 0; i < C; i++) {
        for(int j = 0; j < 16; j++) {
            cin >> clocks.at(j);
        }
        // // 8, 12번이 다르거나 14, 15번이 다르면 절대 답이 나올 수 없으므로 return -1
        // if (clocks[8] != clocks[12] || clocks[14] != clocks[15]) goto NOANSWER;
        // // 8번시계가 움직여야하는 것 만큼 4번 스위치 푸시
        // temp = (12 - clocks[8]);
        // for (int k: switch_clock[4]) clocks[k] += temp;
        // counts += temp / 3;
        // // 이제 4번 스위치는 절대 누르지 않을 것이므로, clock_switch에서 4가 없다고 생각
        // // 11번 시계에 누를 수 있는 스위치가 1번 스위치뿐이므로, 1번 누를 수 있는 횟수 정해짐
        // temp = (12 - clocks[11]);
        // for (int k: switch_clock[1]) clocks[k] += temp;
        // counts += temp / 3;
        // // 이제 1번 스위치는 못 누름
        // // 9, 13번 시계에서 누를 수 있는 스위치가 9번 스위치 뿐이므로 둘이 다르면 return -1
        // // 9, 13번 시계에서 누를 수 있는 스위치가 9번 스위치 뿐이므로 9번 누를 수 있는 횟수 정해짐
        // if (clocks[9] != clocks[13]) goto NOANSWER;
        // temp = (12 - clocks[9]);
        // for (int k: switch_clock[9]) clocks[k] += temp;
        // counts += temp / 3;
        // // 이제 9번 스위치는 절대 ~~~
        // // 10번 시계에서 누를 수 있는 스위치가 2번 뿐이므로 ~~~
        // temp = (12 - clocks[10]);
        // for (int k: switch_clock[2]) clocks[k] += temp;
        // counts += temp / 3;
        // // 이제 2번 스위치는 절대 ~~
        // // 4번 5번 시계가 같아야됨
        // if (clocks[4] != clocks[5]) goto NOANSWER;
        // // 6번 시계에서 3번 스위치밖에 못 누름
        // temp = (12 - clocks[6]);
        // for (int k: switch_clock[3]) clocks[k] += temp;
        // counts += temp / 3;
        // // 이제 3번 스위치 못 누름
        // // 7번 시계에 누를 수 있는 스위치 7번뿐
        // temp = 12 - clocks[7];
        // for (int k: switch_clock[7]) clocks[k] += temp;
        // counts += temp / 3;
        // // 이제 7번 스위치 못 누름
        // // 4, 5번 시계에 누를 수 있는 스위치 8번뿐
        // temp = 12 - clocks[4];
        // for (int k: switch_clock[8]) clocks[k] += temp;
        // counts += temp / 3;
        // // 이제 8번 스위치 못 누름
        // // 0, 2번 시계 다르면 return -1
        // if (clocks[0] != clocks[2]) goto NOANSWER;
        // // 1번 시계에 0번 스위치밖에 못 누름
        // temp = 12 - clocks[1];
        // for (int k: switch_clock[0]) clocks[k] += temp;
        // counts += temp / 3;
        // // 이제 0번 시계에 5번 밖에 못 누름
        // temp = 12 - clocks[0];
        // for (int k: switch_clock[5]) clocks[k] += temp;
        // counts += temp / 3;
        // // 이제 6번 스위치밖에 못 누름, 그리고 3, 14, 15번 시계가 같아야됨
        // if (clocks[3] != clocks[14]) goto NOANSWER;
        // temp = 12 - clocks[3];
        // for (int k: switch_clock[6]) clocks[k] += temp;
        // counts += temp / 3;
        // cout << "여긴왔니?" << endl;
        for (int j = 0; j < 16; j++) {
            int* temp = oneSwitchClock(clock_switch); // temp = {clock number, switch number} for clock with only one switch
            int clock = temp[0];
            int swi = temp[1];
            int rotate = 12 - clocks[clock];
            for (int connectedClock: switch_clock[swi]) {
                clocks[connectedClock] += rotate;
                clock_switch[connectedClock].erase(remove(clock_switch[connectedClock].begin(), clock_switch[connectedClock].end(), swi), clock_switch[connectedClock].end());
            }
            counts += rotate / 3;
        }

        if (!complete(clocks)) goto NOANSWER;

        cout << counts << endl;

    }

    return 0;

    NOANSWER:
    cout << -1 << endl;
    return 0;

}