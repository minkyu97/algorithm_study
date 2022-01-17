#include <iostream>
#include <vector>
#include <string>
#define endl '\n'

using namespace std;

template <class T>
using matrix = vector<vector<T> >;

struct Point {
    int row;
    int col;
};

int N, input;
matrix<int> slate;
vector<Point> dirtys, gems;

bool isSectile(int start, int end, int con, bool isRow) {
    if (isRow) {
        for (int i = start; i <= end; i++) {
            if (slate[con][i] == 2) return false;
        }
    }
    else {
        for (int i = start; i <= end; i++) {
            if (slate[i][con] == 2) return false;
        }
    }
    return true;
}


int solve(int r1, int r2, int c1, int c2, bool isRow, vector<Point>& dirtys, vector<Point>& gems) {
    if (r1 > r2 || c1 > c2) return 0;
    if (gems.size() == 1 && dirtys.size() == 0) return 1;
    int ret = 0;
    if (isRow) {
        for (Point p: dirtys) {
            int row = p.row;
            if (isSectile(c1, c2, row, isRow)) {
                vector<Point> updirtys;
                vector<Point> downdirtys;
                vector<Point> upgems;
                vector<Point> downgems;
                for (Point dp: dirtys) {
                    if (dp.row > row) updirtys.push_back(dp);
                    else if (dp.row < row) downdirtys.push_back(dp);
                }
                for (Point gp: gems) {
                    if (gp.row > row) upgems.push_back(gp);
                    else if (gp.row < row) downgems.push_back(gp);
                }
                if (upgems.size() == 0 || downgems.size() == 0) continue;
                ret += solve(r1, row-1, c1, c2, false, downdirtys, downgems) * solve(row+1, r2, c1, c2, false, updirtys, upgems);
            }
        }
    }
    else {
        for (Point p: dirtys) {
            int col = p.col;
            if (isSectile(r1, r2, col, isRow)) {
                vector<Point> leftdirtys;
                vector<Point> rightdirtys;
                vector<Point> leftgems;
                vector<Point> rightgems;
                for (Point dp: dirtys) {
                    if (dp.col > col) rightdirtys.push_back(dp);
                    else if (dp.col < col) leftdirtys.push_back(dp);
                }
                for (Point gp: gems) {
                    if (gp.col > col) rightgems.push_back(gp);
                    else if (gp.col < col) leftgems.push_back(gp);
                }
                if (rightgems.size() == 0 || leftgems.size() == 0) continue;
                ret += solve(r1, r2, c1, col-1, true, leftdirtys, leftgems) * solve(r1, r2, col+1, c2, true, rightdirtys, rightgems);
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    slate = matrix<int>(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> input;
            if (input == 1) {
                dirtys.push_back(Point {i, j});
            }
            else if (input == 2) {
                gems.push_back(Point {i, j});
            }
            slate[i][j] = input;
        }
    }
    int ret = solve(0, N-1, 0, N-1, true, dirtys, gems) + solve(0, N-1, 0, N-1, false, dirtys, gems);
    if (ret == 0) cout << -1 << endl;
    else cout << ret << endl;
    return 0;
}