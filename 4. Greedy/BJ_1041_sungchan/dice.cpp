#include <iostream>
using namespace std;
int dice[6];
typedef long long ll;
ll N;

int main() {
    cin >> N;

    int min1 = 50;
    for(int i = 0; i < 6; i++) {
        cin >> dice[i];
        if(dice[i] < min1) min1 = dice[i];
    }

    if(N == 1) {
        int max = 0;
        int sum = 0;
        for(int i = 0; i < 6; i++) {
            if(dice[i] > max) max = dice[i];
            sum += dice[i];
        }
        cout << sum - max;
        return 0;
    }

    int min2 = 100;
    for(int i = 0; i < 5; i++) {
        for(int j = i+1; j < 6; j++) {
            if(i+j != 5) {
                if(dice[i] + dice[j] < min2) min2 = dice[i] + dice[j];
            }
        }
    }

    int min3 = 150;
    for(int i = 1; i < 4; i++) {
        for(int j = i+1; j < 5; j++) {
            if(i+j != 5) {
                if(dice[0] + dice[i] + dice[j] < min3) min3 = dice[0] + dice[i] + dice[j];
                if(dice[5] + dice[i] + dice[j] < min3) min3 = dice[5] + dice[i] + dice[j];
            }
        }
    }


    ll one = (5*N*N - 16*N + 12) * (min1);
    ll two = (8*N - 12) * (min2);
    ll three = 4 * (min3);

    cout << one + two + three;
}