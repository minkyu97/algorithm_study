#include <iostream>
#include <vector>
#include <string>
#define endl '\n'

using namespace std;

int C, N;

int max(int ret1, int ret2, int ret3) {
    if (ret1 > ret2 && ret1 > ret3) return ret1;
    return ret2 > ret3 ? ret2 : ret3;
}

int getMax(vector<int>& fence, int left, int right) {
    // base case 1: left = right 일 경우
    if (left == right) return fence[left];
    // base case 2: left + 1 = right 일 경우;
    if (left + 1 == right) {
        int ret1 = fence[left];
        int ret2 = fence[right];
        int ret3 = 2 * (fence[left] < fence[right] ? fence[left] : fence[right]);
        return max(ret1, ret2, ret3);
    }

    int mid = (left + right) / 2;
    // 왼쪽 절반 울타리의 최대 넓이
    int ret1 = getMax(fence, left, mid);
    // 오른쪽 절반 울타리의 최대 넓이
    int ret2 = getMax(fence, mid+1, right);

    // 아래는 왼쪽과 오른쪽에 둘 다에 걸치는 최대 넓이
    int l = mid, r = mid+1;
    int height = fence[l] < fence[r] ? fence[l] : fence[r];
    int width = 2;
    int ret3 = width * height;
    l--, r++;
    // 중간에 걸친 직사각형의 왼쪽 끝 울타리와 오른쪽 끝 울타리가 각각 l, r이면
    // 울타리 범위 안에서 l, r을 1씩 키워가면서 최대값 찾기
    while (true) {
        if (l > left - 1 && r < right + 1) {
            if (fence[l] < fence[r]) {
                height = fence[r] < height ? fence[r] : height;
                int temp = ++width * height;
                ret3 = temp > ret3 ? temp : ret3;
                r++;
            } else {
                height = fence[l] < height ? fence[l] : height;
                int temp = ++width * height;
                ret3 = temp > ret3 ? temp : ret3;
                l--;
            }
        } 
        else if (r < right + 1) {
            height = fence[r] < height ? fence[r] : height;
            int temp = ++width * height;
            ret3 = temp > ret3 ? temp : ret3;
            r++;
        } 
        else if (l > left - 1) {
            height = fence[l] < height ? fence[l] : height;
            int temp = ++width * height;
            ret3 = temp > ret3 ? temp : ret3;
            l--;
        } 
        else break;
    }
    return max(ret1, ret2, ret3);
}

int main() {
    cin >> C;
    for (int i = 0; i < C; i++) {
        cin >> N;
        vector<int> fence(N);
        for (int j = 0; j < N; j++) {
            cin >> fence[j];
        }
        cout << getMax(fence, 0, N-1) << endl;
    }
}