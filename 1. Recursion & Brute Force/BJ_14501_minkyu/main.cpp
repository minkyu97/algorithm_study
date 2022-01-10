#include <iostream>

#define endl '\n'

using namespace std;

int N;
// Ti = T[i], Pi = P[i]
int *T, *P;

// 날짜가 today 일 때부터 추가로 얻을 수 있는 최대 금액
int getMaxPayFrom(int today) {
    // 기저조건 : 시작일이 N보다 크면 0 반환
    if (today > N) return 0;

    int max = 0;
    int temp = 0;

    // start일이 며칠일 때 최대 금액을 얻을 수 있는가?
    for (int start = today; start < N + 1; start++) {
        // start일에 첫 일을 했을 때 얻을 수 있는 최대 금액
        // 만약 start + T[start] > N + 1 이라면, main()에서 설정되어있듯 P[start] = 0, getMaxPayFrom도 기저조건에 의해 0
        temp = P[start] + getMaxPayFrom(start + T[start]);
        if (temp > max) max = temp;
    }
    return max;
}

int main() {
    cin >> N;

    // 날짜 계산의 편의를 위해 +1
    T = new int[N+1];
    P = new int[N+1];

    for (int i = 1; i < N+1; i++) {
        cin >> T[i];
        cin >> P[i];
        // 상담을 하게되면 N을 넘어가버리는 경우 사실 상 상담이 불가능하므로 P[i] = 0
        if (i + T[i] > N + 1) P[i] = 0;
    }

    cout << getMaxPayFrom(1) << endl;

    return 0;
}