#include <iostream>
#include <algorithm>
using namespace std;
int C;
string* W;
string** files;

bool comp(string s1, string s2) {
    return s1 < s2;
}

bool matchMemoized(const string& W, const string& S, int w, int s, int cache[101][101]) {
    int& ret = cache[w][s];
    if(ret != -1) return ret;
    if(w < W.size() && s < S.size() && W[w] == '?' || W[w] == S[s]) return ret = matchMemoized(W, S, w+1, s+1, cache);
    if(w == W.size()) return ret = (s == S.size());
    if(W[w] == '*') {
        if(matchMemoized(W, S, w+1, s, cache) || (s < S.size() && matchMemoized(W, S, w, s+1, cache))) return ret = 1;
    }
    return ret = 0;
}

bool match(const string& w, const string& s) {
    int pos = 0;
    while(pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos])) pos++;

    if(pos == w.size()) return pos == s.size();
    if(w[pos] == '*') {
        for(int skip = 0; pos+skip <= s.size(); skip++) {
            if(match(w.substr(pos+1), s.substr(pos+skip))) return true;
        }
    }
    return false;
}

void finder(string W, string* file_names, int file_number) {
    int cache[101][101];
    for(int i = 0; i <= 100; i++)
        for(int j = 0; j <= 100; j++)
            cache[i][j] = -1;
    string* answer = new string[file_number];
    int answer_num = 0;

    for(int i = 0; i < file_number; i++) {
        if(match(W, file_names[i])) answer[answer_num++] = file_names[i];
        //if(matchMemoized(W, file_names[i], 0, 0, cache)) answer[answer_num++] = file_names[i];
    }

    sort(answer, answer+answer_num, comp);
    for(int i = 0; i < answer_num; i++) {
        cout << answer[i] << endl;
    }
}


int main() {
    cin >> C;
    W = new string[C];
    files = new string*[C];
    int* files_number = new int[C];
    for(int i = 0; i < C; i++) {
        cin >> W[i];
        int n;
        cin >> n;
        files[i] = new string[n];
        files_number[i] = n;
        for(int j = 0; j < n; j++) {
            cin >> files[i][j];
        }
    }

    for(int i = 0; i < C; i++) {
        finder(W[i], files[i], files_number[i]);
    }
}