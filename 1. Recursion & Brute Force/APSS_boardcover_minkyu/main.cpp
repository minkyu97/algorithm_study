#include <iostream>
#include <vector>
#include <string>

using namespace std;

int C, H, W;
// 보드판, 비어있는 칸은 true
vector<vector<bool> > board;

// 좌표값 구조체
struct Point {
    int r;
    int c;
};

// 현재 비어있는 가장 첫번째 칸 찾는 함수 (가장 위쪽, 가장 왼쪽에 있는 비어있는 칸)
Point *findFirst(vector<vector<bool> > &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j]) return new Point {i, j};
        }
    }
    return new Point {-1, -1};
}

// 현재 보드 상태에서 보드를 채울 수 있는 경우의 수 반환
int countCase(vector<vector<bool> > &board, int N) {
    // base case 1. N이 0이면 1가지 경우의 수를 찾은 것이므로 return 1
    if (N == 0) return 1;
    
    // 비어있는 가장 윗줄의, 가장 왼쪽의 좌표를 검색
    Point &firstBlank = *findFirst(board);
    
    // base case 2. firstBlank가 가장 아랫줄이면 ㄱ자 블럭을 놓을 수 없으므로 return 0
    if (firstBlank.r == board.size() - 1) return 0;

    // 찾은 경우의 수 여기에 저장
    int ret = 0;
    board[firstBlank.r][firstBlank.c] = false;
    // 블록을 놓을 수 있는 첫번째 경우의 수
    // 첫번째 빈칸의 바로 아래칸, 왼쪽 아래칸이 비어있는 경우
    if (firstBlank.c != 0 && board[firstBlank.r+1][firstBlank.c] && board[firstBlank.r+1][firstBlank.c-1]) {
        board[firstBlank.r+1][firstBlank.c] = false;
        board[firstBlank.r+1][firstBlank.c-1] = false;
        ret += countCase(board, N-1);
        board[firstBlank.r+1][firstBlank.c] = true;
        board[firstBlank.r+1][firstBlank.c-1] = true;
    }

    // 블록을 놓을 수 있는 2, 3, 4번째 경우의 수
    // 첫번째 빈칸의 아래칸, 오른쪽 아래칸이 비어있는 경우
    // 첫번째 빈칸의 오른칸, 오른쪽 아래칸이 비어있는 경우
    // 첫번째 빈칸의 오른칸, 아래칸이 비어있는 경우

    if (firstBlank.c != board[0].size() - 1) {
        if (board[firstBlank.r+1][firstBlank.c] && board[firstBlank.r+1][firstBlank.c+1]) {
            board[firstBlank.r+1][firstBlank.c] = false;
            board[firstBlank.r+1][firstBlank.c+1] = false;
            ret += countCase(board, N-1);
            board[firstBlank.r+1][firstBlank.c] = true;
            board[firstBlank.r+1][firstBlank.c+1] = true;
        }
        if (board[firstBlank.r][firstBlank.c+1] && board[firstBlank.r+1][firstBlank.c+1]) {
            board[firstBlank.r][firstBlank.c+1] = false;
            board[firstBlank.r+1][firstBlank.c+1] = false;
            ret += countCase(board, N-1);
            board[firstBlank.r][firstBlank.c+1] = true;
            board[firstBlank.r+1][firstBlank.c+1] = true;
        }
        if (board[firstBlank.r][firstBlank.c+1] && board[firstBlank.r+1][firstBlank.c]) {
            board[firstBlank.r][firstBlank.c+1] = false;
            board[firstBlank.r+1][firstBlank.c] = false;
            ret += countCase(board, N-1);
            board[firstBlank.r][firstBlank.c+1] = true;
            board[firstBlank.r+1][firstBlank.c] = true;
        }

    }
    board[firstBlank.r][firstBlank.c] = true;

    return ret;
}

int main() {
    cin >> C;

    // C번 만큼 테스트케이스 돌리기 시작
    for (int i = 0; i < C; i++) {
        cin >> H >> W;

        board = vector<vector<bool> >(H, vector<bool>(W));
        int blank = 0;

        // '#' 입력이 들어온 칸을 1로 변경(1은 채워진 칸을 의미)
        for (int j = 0; j < H; j++) {
            for (int k = 0; k < W; k++) {
                char temp;
                cin >> temp;
                if (temp == '#') {
                    board[j][k] = false;
                } else {
                    board[j][k] = true;
                    blank++;
                }
            }
        }

        if (blank % 3 != 0) {
            cout << 0 << endl;
        }
        else {
            cout << countCase(board, blank / 3) << endl;
        }

    }

    return 0;
}



