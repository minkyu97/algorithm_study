#include <iostream>
#include <algorithm>
using namespace std;
int T, *K, **file, **cumulated;
int cache[501][501];

int cost(int index, int start, int end) {
    if(start == end) return 0;

    int& ret = cache[start][end];
    if(ret != -1) return ret;

    if(start + 1 == end) {
        return ret = file[index][start] + file[index][end];
    }
    if(start + 2 == end) {
        int sum = cumulated[index][start+2];
        if(start > 0) sum -= cumulated[index][start-1];
        return ret = 2 * sum - max(file[index][start], file[index][start+2]);
    }

    int answer = cumulated[index][end];
    if(start > 0) answer -= cumulated[index][start-1];

    int minimum = INT32_MAX;
    for(int i = start; i < end; i++) {
        int cand = cost(index, start, i) + cost(index, i+1, end);
        if(cand < minimum) minimum = cand;
    }

    return ret = answer + minimum;
}

int main() {
    cin >> T;
    K = new int[T];
    file = new int*[T];
    cumulated = new int*[T];
    for(int i = 0; i < T; i++) {
        cin >> K[i];
        file[i] = new int[K[i]];
        cumulated[i] = new int[K[i]];
        cin >> file[i][0];
        cumulated[i][0] = file[i][0];
        for(int j = 1; j < K[i]; j++) {
            cin >> file[i][j];
            cumulated[i][j] = cumulated[i][j-1] + file[i][j];
        }
    }


    for(int i = 0; i < T; i++) {
        for(int j = 0; j <= 500; j++)
            for(int k = 0; k <= 500; k++)
                cache[j][k] = -1;

        cout << cost(i, 0, K[i]-1) << endl;
    }
}