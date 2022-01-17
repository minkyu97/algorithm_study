#include <iostream>
using namespace std;
int N;
long long B;
int** I;

int** product(int** A, int** D) {
    int** C = new int*[N];
    for(int i = 0; i < N; i++) {
        C[i] = new int[N];
        for(int j = 0; j < N; j++) {
            C[i][j] = 0;
            for(int k = 0; k < N; k++) {
                C[i][j] += (A[i][k] * D[k][j]);
            }
            C[i][j] %= 1000;
        }
    }
    return C;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> B;
    int** matrix = new int*[N];
    for(int i = 0; i < N; i++) {
        matrix[i] = new int[N];
        for(int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    I = new int*[N];
    for(int i = 0; i < N; i++) {
        I[i] = new int[N];
        I[i][i] = 1;
    }

    while(B) {
        if(B % 2 == 1) {
            I = product(I, matrix);
        }
        matrix = product(matrix, matrix);
        B /= 2;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << I[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}