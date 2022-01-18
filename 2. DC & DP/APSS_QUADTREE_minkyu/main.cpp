#include <iostream>
#include <vector>
#include <string>
#define endl '\n'

using namespace std;

int C;

// 압축된 쿼드트리 문자열의 시작점이 주어졌을 때, 4개의 하위 요소를 찾아서 상하를 뒤집어서 반환 (하위요소는 반드시 4개이므로 주어진 문자열의 길이를 몰라도 상관 없음)
// start를 call by reference로 준 이유는 하위요소에도 하위요소가 존재하는 경우 문자열의 index가 하위요소의 길이만큼 이동한 후 다음 하위요소를 찾아야 하기 때문
string reverse(string& zip, int& start) {
    // base case: 주어진 문자열의 시작이 b or w이면 하위 요소가 없으므로 자기 자신 반환
    if (zip[start] == 'b' || zip[start] == 'w') return string(1, zip[start]);
    vector<string> child;
    int size = 0;
    while(++start) {
        child.push_back(reverse(zip, start));
        // 하위요소 4개를 찾으면 break
        if (++size == 4) break;
    }
    // 4개의 하위요소를 상하를 뒤집어서 반환
    return "x" + child[2] + child[3] + child[0] + child[1];
}

int main() {
    cin >> C;
    for (int i = 0; i < C; i++) {
        string zip;
        cin >> zip;
        int start = 0;
        cout << reverse(zip, start) << endl;
    }

    return 0;
}