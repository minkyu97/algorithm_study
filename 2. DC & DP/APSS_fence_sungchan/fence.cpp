
#include <iostream>
#include <vector>
using namespace std;
int C, num, height;
vector<vector<int>> boards;

int rectangle(vector<int> board) {
    int size = board.size();
    if(size == 1) return board.at(0);
    if(size == 2) return max(max(board.at(0), board.at(1)), 2 * min(board.at(0), board.at(1)));

    vector<int> left(board.begin(), board.begin() + size/2);
    vector<int> right(board.begin() + size/2, board.begin() + size);
    int left_max = rectangle(left);
    int right_max = rectangle(right);

    int height = min(board.at(size/2 - 1), board.at(size/2));
    int mid_max = 2 * height;

    int left_index = -1;
    for(int i = size/2 - 2; i >= 0; i--) {
        if(board.at(i) >= height) mid_max += height;
        else {
            left_index = i;
            break;
        }
    }

    int right_index = -1;
    for(int i = size/2 + 1; i < size; i++) {
        if(board.at(i) >= height) mid_max += height;
        else {
            right_index = i;
            break;
        }
    }

    if(left_index != -1) {
        if(right_index != -1) {
            int max_height = height;
            while(true) {
                if(left_index < 0) {
                    if(right_index == size) break;
                    max_height = min(max_height, board.at(right_index));
                    if(max_height * (right_index + 1) > mid_max) mid_max = max_height * (right_index + 1);
                    right_index++;
                } else if (right_index == size) {
                    max_height = min(max_height, board.at(left_index));
                    if(max_height * (size - left_index) > mid_max) mid_max = max_height * (size - left_index);
                    left_index--;
                } else {
                    int left_height = board.at(left_index);
                    int right_height = board.at(right_index);
                    if(left_height >= right_height && left_height <= max_height) {
                        max_height = left_height;
                        if((right_index - left_index) * max_height > mid_max) mid_max = (right_index - left_index) * max_height;
                        left_index--;
                    } else if(right_height > left_height && right_height <= max_height) {
                        max_height = right_height;
                        if((right_index - left_index) * max_height > mid_max) mid_max = (right_index - left_index) * max_height;
                        right_index++;
                    } else if(max_height >= left_height) {
                        if((right_index - left_index) * max_height > mid_max) mid_max = (right_index - left_index) * max_height;
                        right_index++;
                    } else if(max_height >= right_height) {
                        if((right_index - left_index) * max_height > mid_max) mid_max = (right_index - left_index) * max_height;
                        left_index--;
                    } else {
                        if((right_index - left_index + 1) * max_height > mid_max) mid_max = (right_index - left_index + 1) * max_height;
                        left_index--;
                        right_index++;
                    }
                }
            }
        } else { // right_index == -1
            int new_height = board.at(left_index);
            if(new_height * (size - left_index) > mid_max) mid_max = new_height * (size - left_index);
            for(int i = left_index - 1; i >= 0; i--) {
                new_height = min(new_height, board.at(i));
                if(new_height * (size - i) > mid_max) mid_max = new_height * (size - i);
            }
        }
    } else if(right_index != -1) { // left_index == -1
        int new_height = board.at(right_index);
        if(new_height * (right_index + 1) > mid_max) mid_max = new_height * (right_index + 1);
        for(int i = right_index + 1; i < size; i++) {
            new_height = min(new_height, board.at(i));
            if(new_height * (i + 1) > mid_max) mid_max = new_height * (i + 1);
        }
    }

    return max(max(left_max, right_max), mid_max);
}

int main() {
    cin >> C;
    for(int i = 0; i < C; i++) {
        cin >> num;
        vector<int> board;
        boards.push_back(board);
        for(int j = 0; j < num; j++) {
            cin >> height;
            boards.at(i).push_back(height);
        }
    }

    for(int i = 0; i < C; i++) {
        cout << rectangle(boards.at(i)) << endl;
    }
}