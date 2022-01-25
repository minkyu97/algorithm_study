#include <iostream>
using namespace std;
int square[183];
bool cache[32768][2];

int count(int num, int part) {
    if(part == 1) {
        if(cache[num][0]) return 0;
        if(cache[num][1]) return 1;
    }

    int ans = 0;

    if(part == 1) {
        for(int i = 1; i <= 182; i++) {
            if(square[i] == num) return cache[num][1] = 1;
            if(square[i] > num) {
                cache[num][0] = 1;
                return 0;
            }
        }
    } else if(part == 2) {
        for(int i = 1; i <= 182; i++) {
            if(square[i] > num/2) break;
            ans += count(num - square[i], 1);
        }
    } else if(part == 3) {
        for(int i = 1; i <= 182; i++) {
            if(square[i] > num/3) break;
            for(int j = i; j <= 182; j++) {
                if(square[j] > (num - square[i])/2) break;
                ans += count(num - square[i] - square[j], 1);
            }
        }
    } else if(part == 4) {
        for(int i = 1; i <= 182; i++) {
            if(square[i] > num/4) break;
            for(int j = i; j <= 182; j++) {
                if(square[j] > (num - square[i])/3) break;
                for(int k = j; k <= 182; k++) {
                    if(square[k] > (num - square[i] - square[j])/2) break;
                    ans += count(num - square[i] - square[j] - square[k], 1);
                }
            }
        }
    }
    return ans;
}

int main() {
    for(int i = 0; i <= 182; i++) square[i] = i * i;
    int* N = new int[255];
    int number = 0;
    for(int i = 0; i < 255; i++) {
        cin >> N[i];
        if(N[i] == 0) break;
        else number++;
    }

    for(int i = 0; i < number; i++) {
        cout << count(N[i], 1) + count(N[i], 2) + count(N[i], 3) + count(N[i], 4) << endl;
    }
}