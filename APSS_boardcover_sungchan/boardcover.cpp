//
// Created by 진성찬 on 2022/01/07.
//

#include <iostream>

int board(char map[20][20], int H, int W) {
    int white = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(map[i][j] == '.') white++;
        }
    }
    if(white % 3 != 0) return 0;
    if(white == 0) return 1;
    int count = 0;

    int first_row = -1;
    int first_col = -1;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(map[i][j] == '.') {
                first_row = i;
                first_col = j;
                break;
            }
        }
        if(first_row != -1 && first_col != -1) break;
    }
    if(first_row == -1 && first_col == -1) return 0;

    if(first_row < H - 1 && first_col < W - 1) { // left upper corner
        if(map[first_row + 1][first_col] == '.' && map[first_row][first_col + 1] == '.') {
            map[first_row][first_col] = '#';
            map[first_row+1][first_col] = '#';
            map[first_row][first_col+1] = '#';
            count += board(map, H, W);
            map[first_row][first_col] = '.';
            map[first_row+1][first_col] = '.';
            map[first_row][first_col+1] = '.';
        }
    }

    if(first_row < H - 1 && first_col < W - 1) { // right upper corner
        if(map[first_row + 1][first_col + 1] == '.' && map[first_row][first_col + 1] == '.') {
            map[first_row][first_col] = '#';
            map[first_row+1][first_col+1] = '#';
            map[first_row][first_col+1] = '#';
            count += board(map, H, W);
            map[first_row][first_col] = '.';
            map[first_row+1][first_col+1] = '.';
            map[first_row][first_col+1] = '.';
        }
    }

    if(first_row < H - 1 && first_col < W - 1) { // left lower corner
        if(map[first_row + 1][first_col] == '.' && map[first_row + 1][first_col + 1] == '.') {
            map[first_row][first_col] = '#';
            map[first_row+1][first_col] = '#';
            map[first_row+1][first_col+1] = '#';
            count += board(map, H, W);
            map[first_row][first_col] = '.';
            map[first_row+1][first_col] = '.';
            map[first_row+1][first_col+1] = '.';
        }
    }

    if(first_row < H - 1 && first_col > 0) { // right lower corner
        if(map[first_row + 1][first_col] == '.' && map[first_row + 1][first_col - 1] == '.') {
            map[first_row][first_col] = '#';
            map[first_row+1][first_col] = '#';
            map[first_row+1][first_col-1] = '#';
            count += board(map, H, W);
            map[first_row][first_col] = '.';
            map[first_row+1][first_col] = '.';
            map[first_row+1][first_col-1] = '.';
        }
    }

    return count;
}

int main() {
    int case_number;
    std::cin >> case_number;
    int *H = new int[case_number];
    int *W = new int[case_number];
    char map[30][20][20];
    bool *exists = new bool[case_number];

    for(int i = 0; i < case_number; i++) {
        std::cin >> H[i] >> W[i];
        exists[i] = false;
        for(int j = 0; j < H[i]; j++) {
            for(int k = 0; k < W[i]; k++) {
                std::cin >> map[i][j][k];
                if(map[i][j][k] == '.') exists[i] = true;
            }
        }
    }

    for(int i = 0; i < case_number; i++) {
        if(exists[i]) std::cout << board(map[i], H[i], W[i]) << std::endl;
        else std::cout << 0 << std::endl;
    }

    delete[] H, W, exists;
    return 0;
}