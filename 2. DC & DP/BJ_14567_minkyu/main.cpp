#include <iostream>
#define endl '\n'

using namespace std;

int N, M, from, to, temp;
int(* pre)[2];
int* out;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    pre = new int[M][2];
    out = new int[N+1];
    for (int i = 0; i < M; i++) {
        cin >> pre[i][0] >> pre[i][1];
    }
    for (int code = 1; code <= N; code++) {
        out[code] = 1;
        for (int j = 0; j < M; j++) {
            if (pre[j][1] == code && out[pre[j][0]] + 1 > out[code]) out[code] = out[pre[j][0]] + 1;
        }
        cout << out[code] << ' ';
    }
}