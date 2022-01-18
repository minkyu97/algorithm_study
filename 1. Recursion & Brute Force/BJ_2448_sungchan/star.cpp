//
// Created by 진성찬 on 2022/01/08.
//


#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N;
string stars = "  *  \n"
               " * * \n"
               "*****";

string star(int N);

vector<string> split(string s, string divid) {
    vector<string> v;
    int start = 0;
    int d = s.find(divid);
    while(d != -1) {
        v.push_back(s.substr(start, d-start));
        start = d + 1;
        d = s.find(divid, start);
    }
    v.push_back(s.substr(start, d - start));
    return v;
}

string combine(int N) {
    string one = star(N);
    vector<string> lines = split(one, "\n");

    string two = "";
    for(int i = 0; i < N; i++) {
        two += lines.at(i);
        two += " ";
        two += lines.at(i);
        if(i != N-1) two += "\n";
    }

    string new_lines = "";
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) new_lines += ' ';
        new_lines += lines.at(i);
        for(int j = 0; j < N; j++) new_lines += ' ';
        new_lines += "\n";
    }
    return new_lines + two;
}

string star(int N) {
    if(N == 3) return stars;
    else return combine(N/2);
}

int main() {
    cin >> N;
    cout << star(N);
}
