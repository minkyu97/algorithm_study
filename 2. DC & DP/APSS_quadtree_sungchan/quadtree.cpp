//
// Created by 진성찬 on 2022/01/13.
//

#include <iostream>
using namespace std;
int C;

string upside_down(string input) {
    if(input.size() == 1) return input;
    int* index = new int[5];
    index[0] = 1;
    for(int i = 1; i < 4; i++) {
        int x_num = 0;
        int other_num = 0;
        int idx = index[i-1];
        while(x_num * 3 + 1 != other_num) {
            if(input.at(idx++) == 'x') x_num++;
            else other_num++;
        }
        index[i] = idx;
    }
    index[4] = input.size();

    string* substring = new string[4];
    for(int i = 0; i < 4; i++) {
        substring[i] = upside_down(input.substr(index[i], index[i+1] - index[i]));
    }
    return "x" + substring[2] + substring[3] + substring[0] + substring[1];
}

int main() {
    cin >> C;
    string* images = new string[C];
    for(int i = 0; i < C; i++) {
        cin >> images[i];
    }
    for(int i = 0; i < C; i++) {
        cout << upside_down(images[i]) << endl;
    }
}