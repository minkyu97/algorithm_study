#include <iostream>
#include <vector>
#include <string>

#define endl '\n'

using namespace std;

int N;

// size 가 3인 기저케이스
vector<string> size3 {
    "  *  "s,
    " * * "s,
    "*****"s
};

// size가 매개변수로 들어왔을 때 삼각형을 vector<string>으로 저장해서 return
vector<string> makeStar(int size) {
    // 기저조건 : size 3일 때
    if (size == 3) {
        return size3;
    }
    // 크기가 size / 2 인 삼각형
    vector<string> before = makeStar(size / 2);
    int temp = size / 2;

    // 윗 부분 그리기
    vector<string> top(before.size());
    for(int i = 0; i < before.size(); i++) {
        top[i] = string(temp, ' ') + before[i] + string(temp, ' ');
    }
    
    // 아랫부분 그리기
    vector<string> bottom(before.size());
    for(int i = 0; i < before.size(); i++) {
        bottom[i] = before[i] + " " + before[i];
    }
    top.insert(top.end(), bottom.begin(), bottom.end());
    return top;
}

int main() {
    cin >> N;
    vector<string> triangle = makeStar(N);
    for (string s: triangle) {
        cout << s << endl;
    }
    
    return 0;
}