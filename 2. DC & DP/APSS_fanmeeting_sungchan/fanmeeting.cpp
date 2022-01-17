#include <iostream>
#include <vector>
using namespace std;
int C;

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<int> c(a.size() + b.size(), 0);
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < b.size(); j++)
            c[i+j] += a[i] * b[j];
    return c;
}

void addTo(vector<int>& a, const vector<int>& b, int k) {
    if(a.size() < b.size() + k) {
        for(int i = a.size(); i < b.size() + k; i++) a.push_back(0);
    }
    for(int i = 0; i < b.size(); i++) a[i+k] += b[i];
}

void subFrom(vector<int>& a, const vector<int>& b) {
    for(int i = 0; i < b.size(); i++) a[i] -= b[i];
}

vector<int> karatsuba(vector<int> a, vector<int> b) {
    int an = a.size(), bn = b.size();
    if(an < bn) return karatsuba(b, a);
    if(an == 0 || bn == 0) return vector<int>();
    if(an <= 100) return multiply(a, b);
    int half = an / 2;

    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());
    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);

    addTo(a0, a1, 0);
    addTo(b0, b1, 0);
    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half + half);

    return ret;
}

int counter(string members, string fans, bool trim) {
    int member_size = members.size();
    int fan_size = fans.size();

    vector<int> male_member(member_size), male_fan(fan_size);
    for(int i = 0; i < member_size; i++) male_member[i] = (members[i] == 'M');
    for(int i = 0; i < fan_size; i++) male_fan[i] = (fans[fan_size - i - 1] == 'M');
    vector<int> karatsubas = karatsuba(male_member, male_fan);
    int answer = 0;
    for(int i  = member_size - 1; i < fan_size; i++) {
        if(karatsubas[i] == 0) answer++;
    }
    return answer;
}

int main() {
    cin >> C;
    string* members = new string[C];
    string* fans = new string[C];
    for(int i = 0; i < C; i++) {
        cin >> members[i];
        cin >> fans[i];
    }

    for(int i = 0; i < C; i++) {
        cout << counter(members[i], fans[i], false) << endl;
    }
}