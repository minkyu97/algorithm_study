#include <iostream>
#include <vector>
#include <string>
#define endl '\n'

using namespace std;
typedef long long ll;
template <class T>
using matrix = vector<vector<T> >;

template <class T>
std::ostream& operator << (std::ostream &out, const matrix<T> &m)
{
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++) {
            out << m[i][j] << ' ';
        }
        out << endl;
    }
    return out;
}

template <class T>
matrix<T> operator * (matrix<T>& m1, matrix<T>& m2) {
    int size = m1.size();
    assert(m1[0].size() == size);
    matrix<T> ret (size, vector<T>(size, 0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                ret[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return ret;
}

int N;
ll B;
matrix<int> m;
matrix<int> one;
int input;
vector<bool> plusOne;

void order() {
    while(B != 1) {
        if (B % 2 == 0) {
            plusOne.push_back(false);
            B /= 2;
        }
        else {
            plusOne.push_back(true);
            B -= 1;
        }
        // cout << B << endl;
    }
    // for (bool* it = plusOne.begin(); it )
}

void solve() {
    vector<bool>::reverse_iterator rit;
    for (rit = plusOne.rbegin(); rit != plusOne.rend(); rit++) {
        if (*rit) m = m * one;
        else m = m * one;
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

    order();
    solve();
    cout << m;

    return 0;
}