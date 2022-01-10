//
// Created by 진성찬 on 2022/01/07.
//

#include <iostream>
#include <algorithm>

bool completed(int clock[16]) {
    bool complete = true;
    for(int i = 0; i < 16; i++) {
        if(clock[i] % 12 != 0) {
            complete = false;
            break;
        }
    }
    return complete;
}

int switches[10][5] = {
        {0, 1, 2, -1, -1},
        {3, 7, 9, 11, -1},
        {4, 10, 14, 15, -1},
        {0, 4, 5, 6, 7},
        {6, 7, 8, 10, 12},
        {0, 2, 14, 15, -1},
        {3, 14, 15, -1, -1},
        {4, 5, 7, 14, 15},
        {1, 2, 3, 4, 5},
        {3, 4, 5, 9, 13}
};

int sync(int clock[16], int start) {
    int minimum;
    if(completed(clock)) return 0;
    if(start == 9) {
        for(int i = 1; i < 4; i++) {
            for(int j = 0; j < 5; j++) {
                clock[switches[9][j]] += 3;
            }
            if(completed(clock)) {
                for(int j = 0; j < 5; j++) {
                    clock[switches[9][j]] -= 3*i;
                }
                return i;
            }
        }
        for(int j = 0; j < 5; j++) {
            clock[switches[9][j]] -= 9;
        }
        return 31;
    } else {
        int count;
        minimum = 31;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 5; j++) {
                if(switches[start][j] != -1 && i != 0) clock[switches[start][j]] += 3;
            }
            count = i + sync(clock, start+1);
            if(count < minimum) minimum = count;
        }
        for(int j = 0; j < 5; j++) {
            if(switches[start][j] != -1) clock[switches[start][j]] -= 9;
        }
    }

    if(minimum > 30 && start == 0) return -1;
    return minimum;
}

int main() {
    int case_number;
    std::cin >> case_number;
    int** clock = new int*[case_number];
    for(int i = 0; i < case_number; i++) {
        clock[i] = new int[16];
    }

    for(int i = 0; i < case_number; i++) {
        for(int j = 0; j < 16; j++) {
            std::cin >> clock[i][j];
        }
    }

    for(int i = 0; i < case_number; i++) {
        std::cout << sync(clock[i], 0) << std::endl;
    }

}