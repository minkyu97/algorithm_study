#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N;

int main() {
    cin >> N;
    int* acid = new int[N];
    for(int i = 0; i < N; i++) {
        cin >> acid[i];
    }
    sort(acid, acid+N);

    int acid_index = -1;
    for(int i = 0; i < N; i++) {
        if(acid[i] > 0) {
            acid_index = i;
            break;
        }
    }
    if(acid_index == -1) {
        cout << acid[N-2] << " " << acid[N-1];
        return 0;
    }
    if(acid_index == 0) {
        cout << acid[0] << " " << acid[1];
        return 0;
    }

    int minimum = INT32_MAX;
    pair<int, int> index;
    int limit = N-1;
    for(int i = 0; i < acid_index; i++) {
        bool done = false;
        for(int j = acid_index; j <= limit; j++) {
            int cand = acid[i]+acid[j];
            if(cand > 0) {
                if(cand < minimum) {
                    minimum = cand;
                    index.first = i;
                    index.second = j;
                    limit = j;
                }
                if(j > acid_index) {
                    int cand2 = -(acid[i]+acid[j-1]);
                    if(cand2 < minimum) {
                        minimum = cand2;
                        index.first = i;
                        index.second = j-1;
                    }
                }
                done = true;
                break;
            } else if(cand == 0) {
                cout << acid[i] << " " << acid[j];
                return 0;
            }
        }
        if(!done) {
            int cand3 = -(acid[i] + acid[limit]);
            if(cand3 < minimum) {
                minimum = cand3;
                index.first = i;
                index.second = limit;
            }
        }
    }

    if(acid_index > 1) {
        if(acid[acid_index-2] + acid[acid_index-1] > -minimum) {
            minimum = -(acid[acid_index-2] + acid[acid_index-1]);
            index.first = acid_index-2;
            index.second = acid_index-1;
        }
    }
    if(N-acid_index > 1) {
        if(acid[acid_index] + acid[acid_index+1] < minimum) {
            index.first = acid_index;
            index.second = acid_index+1;
        }
    }

    cout << acid[index.first] << " " << acid[index.second];
}