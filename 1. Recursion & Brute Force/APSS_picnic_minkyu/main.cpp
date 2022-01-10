#include <iostream>
#include <vector>
#include <string>

using namespace std;

int C, n, m;
bool (*areFriends)[10];

int countParings(bool (&taken)[10]) {
    int firstFree = -1;
    for (int i = 0; i < n; i++) {
        if (!taken[i]) {
            firstFree = i;
            break;
        }
    }

    if (firstFree == -1) return 1;
    int ret = 0;
    for(int pairWith = firstFree+1; pairWith < n; pairWith++) {
        if(!taken[pairWith] && areFriends[firstFree][pairWith]) {
            taken[firstFree] = taken[pairWith] = true;
            ret += countParings(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }

    return ret;
}

int main() {
    cin >> C;
    for (int i = 0; i < C; i++) {
        bool temp[10][10] = {0};
        areFriends = temp;

        cin >> n >> m;

        for (int j = 0; j < m; j++) {
            int student1, student2;
            cin >> student1 >> student2;
            areFriends[student1][student2] = true;
            areFriends[student2][student1] = true;
        }
        
        bool taken[10] = {0};

        int result = countParings(taken);
        
        cout << result << endl;
    }
    return 0;
}

