#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
int N, M;
// 크레인 무게 저장
vector<int> crane;
// 각 크레인마다 나를 박스 수 저장
vector<int> allo;
// 박스 무게 저장
vector<int> box;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    crane = vector<int>(N);
    allo = vector<int>(N, 0);
    for (int i = 0; i < N; i++) cin >> crane[i];
    // 크레인 내림차순 정렬
    sort(crane.rbegin(), crane.rend());
    cin >> M;
    box = vector<int>(M);
    for (int i = 0; i < M; i++) cin >> box[i];
    // 박스 내림차순 정렬
    sort(box.rbegin(), box.rend());
    // 못 나르는 경우
    if (box.front() > crane.front()) {
        cout << -1 << endl;
        return 0;
    }
    // 가장 무거운 박스부터 시작
    for (vector<int>::iterator b = box.begin(); b != box.end(); b++) {
        // 가장 무거운 크레인 부터 시작
        for (int i = 0; i < N; i++) {
            /////// 최선의 선택 하기 ////////
            // 이 박스를 다음 크레인에게 맡길 수 없거나
            // 다음 크레인에 박스가 더 많으면
            // 이 박스는 현재 크레인에서 처리
            if (i == N-1 || crane[i+1] < *b || allo[i] < allo[i+1]) {
                allo[i]++;
                break;
            }
        }
    }
    int a = 0;
    // 가장 오랙 걸리는 크레인 찾기
    for (int i = 0; i < N; i++) {
        a = max(a, allo[i]);
    }
    cout << a << endl;

}