#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<vector<int> > board;

void setQueens(vector<vector<int> > &board, int row, int col) {
    for (int i = 0; i < N; i++) {
        board[row][i]++;
        board[i][col]++;
    }
    board[row][col]--;
    for (int i = 1; i < N; i++) {
        int x = row + i;
        int y = col + i;
        if(x == N || y == N) break;
        board[x][y]++;
    }
    for (int i = 1; i < N; i++) {
        int x = row - i;
        int y = col - i;
        if(x == -1 || y == -1) break;
        board[x][y]++;
    }
    for (int i = 1; i < N; i++) {
        int x = row + i;
        int y = col - i;
        if(x == N || y == -1) break;
        board[x][y]++;
    }
    for (int i = 1; i < N; i++) {
        int x = row - i;
        int y = col + i;
        if(x == -1 || y == N) break;
        board[x][y]++;
    }
};

void unSetQueens(vector<vector<int> > &board, int row, int col) {
    for (int i = 0; i < N; i++) {
        board[row][i]--;
        board[i][col]--;
    }
    board[row][col]++;
    for (int i = 1; i < N; i++) {
        int x = row + i;
        int y = col + i;
        if(x == N || y == N) break;
        board[x][y]--;
    }
    for (int i = 1; i < N; i++) {
        int x = row - i;
        int y = col - i;
        if(x == -1 || y == -1) break;
        board[x][y]--;
    }
    for (int i = 1; i < N; i++) {
        int x = row + i;
        int y = col - i;
        if(x == N || y == -1) break;
        board[x][y]--;
    }
    for (int i = 1; i < N; i++) {
        int x = row - i;
        int y = col + i;
        if(x == -1 || y == N) break;
        board[x][y]--;
    }
};

int countCase(vector<vector<int> > &board, int row) {
    int ret = 0;

    // 기저조건
    if (row == 0) {
        for(int zero: board[0]) {
            if (zero == 0) ret++;
        }
        return ret;
    }

    for (int i = 0; i < N; i++) {
        if (board[row][i] == 0) {
            setQueens(board, row, i);
            ret += countCase(board, row - 1);
            unSetQueens(board, row, i);
        }
    }
    
    return ret;
}

int main() {
    cin >> N;
    board = vector<vector<int> >(N, vector<int>(N, 0));
    cout << countCase(board, N-1) << endl;
    return 0;
}