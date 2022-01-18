#include <iostream>
using namespace std;
int N;
int** stone;

int counter(int startrow, int startcol, int endrow, int endcol, bool rowwise) {
    if(startrow > endrow || startcol > endcol) return 0;

    int gem = 0;
    int impurity = 0;
    int* gem_row = new int[15];
    int* gem_col = new int[15];
    int* impurity_row = new int[15];
    int* impurity_col = new int[15];
    for(int i = startrow; i <= endrow; i++) {
        for(int j = startcol; j <= endcol; j++) {
            if(stone[i][j] == 2) {
                gem_row[gem] = i;
                gem_col[gem] = j;
                gem++;
            } else if(stone[i][j] == 1) {
                impurity_row[impurity] = i;
                impurity_col[impurity] = j;
                impurity++;
            }
        }
    }
    if(gem == 0) return 0;
    else if(gem == 1) {
        if(impurity == 0) return 1;
        else return 0;
    } else if(impurity == 0) return 0;

    if(rowwise) { // same row
        int count = 0;
        for(int i = 0; i < impurity; i++) {
            bool possible = true;
            for(int j = 0; j < gem; j++) {
                if(gem_row[j] == impurity_row[i]) {
                    possible = false;
                    break;
                }
            }
            if(possible) {
                count += counter(startrow, startcol, impurity_row[i]-1, endcol, false) * counter(impurity_row[i]+1, startcol, endrow, endcol, false);
            }
        }
        return count;
    } else { // same col
        int count = 0;
        for(int j = 0; j < impurity; j++) {
            bool possible = true;
            for(int i = 0; i < gem; i++) {
                if(gem_col[i] == impurity_col[j]) {
                    possible = false;
                    break;
                }
            }
            if(possible) {
                count += counter(startrow, startcol, endrow, impurity_col[j]-1, true) * counter(startrow, impurity_col[j]+1, endrow, endcol, true);
            }
        }
        return count;
    }
}

int main() {
    cin >> N;
    stone = new int*[N];
    for(int i = 0; i < N; i++) {
        stone[i] = new int[N];
        for(int j = 0; j < N; j++) {
            cin >> stone[i][j];
        }
    }

    int answer = counter(0,0,N-1,N-1, true) + counter(0,0,N-1,N-1, false);
    if(answer == 0) cout << -1;
    else cout << answer;
}