#include <iostream>
#include <algorithm>
#define MOD 1000000007
int N;
using namespace std;
string* names;
int* start_num;
int* end_num;
long long factorial[27];

bool comp(string s1, string s2) {
    return s1 < s2;
}

void mutual_finder(string* names) {
    start_num = new int[N-1];
    end_num = new int[N-1];
    for(int i = 0; i < N - 1; i++) { // finding mutual string between names[i] and names[i+1]
        string mutual = "";
        int len1 = names[i].size();
        int len2 = names[i+1].size();
        for(int j = 0; j < len1; j++) {
            if(j >= len2) break;
            else if(names[i][j] == names[i+1][j]) mutual += names[i][j];
            else break;
        }
        if(mutual == "") {
            start_num[i] = 0;
            end_num[i] = N-1;
        } else {
            int mutual_size = mutual.size();
            bool start_done = false;
            for(int j = 0; j <= i; j++) {
                if(names[j].size() < mutual_size) continue;
                for(int k = 0; k < mutual_size; k++) {
                    if(mutual[k] != names[j][k]) break;
                    if(k == mutual_size - 1) {
                        start_done = true;
                        start_num[i] = j;
                    }
                }
                if(start_done) break;
            }
            bool end_done = false;
            for(int j = N-1; j >= i+1; j--) {
                if(names[j].size() < mutual_size) continue;
                for(int k = 0; k < mutual_size; k++) {
                    if(mutual[k] != names[j][k]) break;
                    if(k == mutual_size - 1) {
                        end_done = true;
                        end_num[i] = j;
                    }
                }
                if(end_done) break;
            }
        }
    }
    factorial[0] = 1;
    for(int i = 1; i <= 26; i++) factorial[i] = (i * factorial[i-1]) % MOD;
}

int counter(int start, int end) {
    if(start == end) return 1;
    else if(start + 1 == end) return 2;

    int index_number = 0;
    int* index = new int[end-start];
    for(int i = start; i < end; i++) {
        if(start_num[i] == start && end_num[i] == end) {
            index[index_number++] = i;
        }
    }
    index[index_number] = end;

    long long count = (factorial[index_number + 1] * counter(start, index[0])) % MOD;
    for(int i = 0; i < index_number; i++) {
        count = (count * counter(index[i] + 1, index[i+1])) % MOD;
    }

    return count;
}

int main() {
    cin >> N;
    names = new string[N];
    for(int i = 0; i < N; i++) {
        cin >> names[i];
    }
    sort(names, names+N, comp);
    mutual_finder(names);
    cout << counter(0, N-1);
}
