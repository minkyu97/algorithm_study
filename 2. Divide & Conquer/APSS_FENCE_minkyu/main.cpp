#include <iostream>
#include <vector>
#include <string>
#define endl '\n'

using namespace std;

int C, N;
vector<int> fence(20001);

int getMax(int left, int right) {
    // base case 1: left = right 일 경우
    if (left == right) return fence[left];

    int mid = (left + right) / 2;
    // 가운데를 걸치지 않는 울타리의 최대 넓이
    int ret1 = max(getMax(left, mid), getMax(mid+1, right));

    // 아래는 왼쪽과 오른쪽에 둘 다에 걸치는 최대 넓이
    int l = mid, r = mid+1;
    int height = fence[l] < fence[r] ? fence[l] : fence[r];
    int width = 2;
    int ret2 = width * height;
    // 중간에 걸친 직사각형의 왼쪽 끝 울타리와 오른쪽 끝 울타리가 각각 l, r이면
    // 울타리 범위 안에서 l, r을 1씩 키워가면서 최대값 찾기
    while (left < l || r < right) {
        if (r < right && (l < left || fence[l-1] < fence[r+1])) {
            r++;
            height = min(fence[r], height);
        } else {
            l--;
            height = min(fence[l], height);
        }
        ret2 = max(ret2, ++width * height);
    }
    return max(ret1, ret2);
}

int main() {
    cin >> C;
    for (int i = 0; i < C; i++) {
        cin >> N;
        for (int j = 0; j < N; j++) {
            cin >> fence[j];
        }
        cout << getMax(0, N-1) << endl;
    }
}