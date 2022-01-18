#include <iostream>
using namespace std;
int N, M;

int* counter(bool** course) {
    int* answer = new int[N];
    for(int i = 0; i < N; i++) answer[i] = 1;
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            if(course[i][j]) answer[j] = max(answer[i] + 1, answer[j]);
        }
    }
    return answer;
}

int main() {
    cin >> N >> M;
    bool** course = new bool*[N];
    for(int i = 0; i < N; i++) course[i] = new bool[N];

    for(int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        course[A-1][B-1] = true;
    }

    int* answer = counter(course);
    for(int i = 0; i < N; i++) {
        cout << answer[i] << " ";
    }
}