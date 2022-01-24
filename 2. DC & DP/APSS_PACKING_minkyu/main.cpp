#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;
using matrix = vector<vector<int> >;

int C, N, W;
vector<string> name;
vector<int*> info;
matrix cache;
matrix choice;

// 번호가 start 이상의 물건부터 주울 수 있을 때 남은 공간에 추가 가능한 최대 절박함
int getMaxNeed(int start, int space) {
    if (start == N) return 0;
    if (space == 0) return 0;
    int& ret = cache[start][space];
    int& c = choice[start][space];
    if (ret) return ret;
    for (int i = start; i < N; i++) {
        if (space < info[i][0]) {
            continue;
        }
        else {
            int temp = info[i][1] + getMaxNeed(i+1, space - info[i][0]);
            if (temp > ret) {
                ret = temp;
                c = i;
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> C;
    for (int i = 0; i < C; i++) {
        cin >> N >> W;
        name = vector<string> (N+1);
        info = vector<int*> (N+1);
        cache = matrix(N+1, (vector<int> (W+1)));
        choice = matrix(N+1, (vector<int> (W+1, -1)));
        for (int j = 0; j < N; j++) {
            info[j] = new int[2];
            cin >> name[j] >> info[j][0] >> info[j][1];
        }
        cout << getMaxNeed(0, W) << ' ';
        int number = 0;
        int start = 0;
        vector<int> mychoice;
        while(choice[start][W] != -1) {
            mychoice.push_back(choice[start][W]);
            start = choice[start][W] + 1;
            W -= info[start-1][0];
            number++;
        }
        cout << number << endl;
        for (int j = 0; j < number; j++) {
            cout << name[mychoice[j]] << endl;
        }
    }
}