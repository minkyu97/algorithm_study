#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int N;

int main() {
    cin >> N;
    priority_queue<int, vector<int>, greater<>> numbers;
    int number;
    for(int i = 0; i < N; i++) {
        cin >> number;
        numbers.push(number);
    }

    int ans = 0;
    while(numbers.size() > 1) {
        int num1 = numbers.top();
        numbers.pop();
        int num2 = numbers.top();
        numbers.pop();
        numbers.push(num1 + num2);
        ans += (num1 + num2);
    }
    cout << ans;
}