#include <iostream>
using namespace std;
int N;
int *day1, *day2;
int ret[1000][1000];

int counter(int start1, int start2, int minimum) {
    if(start1 >= N || start2 >= N) return 0;
    if(ret[start1][start2] != -1) return ret[start1][start2];

    int startnum = -1;
    for(int i = start1; i < N; i++) {
        if(day1[i] > minimum) {
            startnum = day1[i];
            break;
        }
    }
    if(startnum == -1) return 0;

    int index2 = -1;
    for(int i = start2; i < N; i++) {
        if(day2[i] == startnum) {
            index2 = i;
            break;
        }
    }
    if(index2 == -1) return ret[start1][start2] = counter(start1+1, start2, minimum);
    else {
        int max = 1;
        for(int i = start1 + 1; i < N; i++) {
            if(day1[i] > startnum) {
                int count = 1 + counter(i, index2+1, startnum);
                if(count > max) max = count;
            }
        }
        for(int i = start1 + 1; i < N; i++) {
            if(day1[i] > minimum && counter(i, start2, minimum) > max) max = counter(i, start2, minimum);
        }
        return ret[start1][start2] = max;
    }
}

int main() {
    for(int i = 0; i < 1000; i++)
        for(int j = 0; j < 1000; j++)
            ret[i][j] = -1;

    cin >> N;
    day1 = new int[N];
    day2 = new int[N];
    for(int i = 0; i < N; i++) cin >> day1[i];
    for(int i = 0; i < N; i++) cin >> day2[i];
    int answer = counter(0, 0, 0);
    cout << answer;
}