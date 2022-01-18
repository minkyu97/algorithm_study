#include <iostream>
#include <vector>
#include <string>

#define endl '\n'

using namespace std;

int N;
string students;

int factorial(int num) {
    return 0; // num! 반환 예정
}

int nonEmptyBucket(vector<vector<int> > *buckets) {
    int ret = 0;
    for(vector<int> bucket: *buckets) {
        if (bucket.size() != 0) ret++;
    }

    return ret;
}

// student 집합이 들어왔을 때 order번째 글자 이상의 이름에 대해서 규칙에 맞춰 세울 수 있는 경우의 수 반환
int counts(vector<int> *studentslist, int order) {
    int number = studentslist->size();
    if (number < 3) {
        switch (number) {
            case 0:
                return 0;
            case 1:
                return 1;
            case 2:
                return 2;
        }
    }
    vector<vector<int> > buckets(27);

    return 0;
}

int main() {
    cin >> N;

    students = new string(N);
    int studentslist[N];

    for (int i = 0; i < N; i++) {
        cin >> students[i];
        studentslist[i] = i;
    }

    cout << counts(studentslist, 0) << endl;



    
    return 0;
}