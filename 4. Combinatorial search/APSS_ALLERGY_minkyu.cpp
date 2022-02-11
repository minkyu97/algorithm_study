#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using matrix = vector<vector<int> >;
int T, n, m;
int MAX_DEPTH;
// nameIndex[name] : table에서 해당 이름을 가진 사람의 행 번호 저장
map<string, int> nameIndex;
// foodEater[i] : i번째 음식을 먹을 수 있는 사람들의 리스트
matrix foodEater;
// eaterFood[i] : i번째 사람이 먹을 수 있는 음식 리스트
matrix eaterFood;
// 현재 상태
vector<int> edible;

int search(int start) {
    return distance(edible.begin(), find(edible.begin(), edible.end(), 0));
}

void select(int food) {
    for (int saram: foodEater[food]) {
        edible[saram]++;
    }
}

void unselect(int food) {
    for (int saram: foodEater[food]) {
        edible[saram]--;
    }
}

// start 번 음식부터 시작
void solve(int start, int num) {
    if (num >= MAX_DEPTH) return;
    if (find(edible.begin(), edible.end(), 0) == edible.end()) {
        MAX_DEPTH = num;
        return;
    }
    int inedible = search(start);
    for (int food: eaterFood[inedible]) {
        select(food);
        solve(food+1, num+1);
        unselect(food);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while(T--) {
        MAX_DEPTH = 21;
        cin >> n >> m;
        foodEater = matrix(m);
        eaterFood = matrix(n);
        edible = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            string name;
            cin >> name;
            nameIndex[name] = i;
        }
        for (int i = 0; i < m; i++) {
            int num;
            cin >> num;
            while(num--) {
                string name;
                cin >> name;
                int person = nameIndex[name];
                foodEater[i].push_back(person);
                eaterFood[person].push_back(i);
            }
        }
        solve(0, 0);
        cout << MAX_DEPTH << endl;
    }
}