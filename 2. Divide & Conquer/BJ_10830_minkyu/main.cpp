#include <iostream>
#include <vector>
#include <string>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<vector<int> > matrix;

int N;
ll B;
matrix m;
matrix one;
int input;
vector<bool> plusOne;

void printMatrix(matrix& mat) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
}

void multiply(matrix& A, matrix& B) {
    matrix newA (N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                newA[i][j] += A[i][k] * B[k][j];
                if (newA[i][j] > 999) newA[i][j] %= 1000;
            }
        }
    }
    A = newA;
}

void order(ll B) {
    while(B != 1) {
        if (B % 2 == 0) {
            plusOne.push_back(false);
            B /= 2;
        }
        else {
            plusOne.push_back(true);
            B -= 1;
        }
    }
}

void solve() {
    vector<bool>::reverse_iterator rit;
    for (rit = plusOne.rbegin(); rit != plusOne.rend(); rit++) {
        if (*rit) multiply(m, one);
        else multiply(m, m);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        m.push_back(vector<int>());
        one.push_back(vector<int>());
        for (int j = 0; j < N; j++) {
            cin >> input;
            m[i].push_back(input);
            one[i].push_back(input);
        }
    }

    order(B);
    solve();
    printMatrix(m);

    return 0;
}