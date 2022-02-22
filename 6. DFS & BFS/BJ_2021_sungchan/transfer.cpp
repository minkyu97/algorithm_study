#include <iostream>
#include <vector>
#include <set>
using namespace std;
int N, L;
int station, src, dest;

int main() {
    cin >> N >> L;
    vector<vector<int>> line(L+1);
    for(int i = 1; i <= L; i++) {
        cin >> station;
        while(station != -1) {
            line[i].push_back(station);
            cin >> station;
        }
    }

    vector<vector<int>> link(N+1);
    for(int i = 1; i <= L; i++) {
        for(int j: line[i]) {
            link[j].push_back(i);
        }
    }
    cin >> src >> dest;
    if(src == dest) {
        cout << 0;
        return 0;
    }

    if(link[src].empty()) {
        cout << -1;
        return 0;
    }

    vector<bool> visited_line(L+1, false); // 방문한 호선
    vector<bool> visited_station(N+1, false); // 방문한 역
    set<int> tovisit; // 방문할 호선

    for(int i: link[src]) {
        tovisit.insert(i); // src와 연결된 호선 추가
    }

    visited_station[src] = true; // src 방문 체크

    int ans = 0;
    while(!tovisit.empty()) { // 방문할 호선이 있을 때 반복
        for(int i: tovisit) {
            visited_line[i] = true; // 호선 방문 체크
        }
        set<int> temp(tovisit);
        for(int i : tovisit) { // ans번 환승하여 방문할 호선들
            for(int j: line[i]) { // 각 호선에 연결된 역들
                if(visited_station[j]) continue;
                visited_station[j] = true;
                if(j == dest) {
                    cout << ans;
                    return 0;
                }
                for(int k: link[j]) {
                    if(!visited_line[k]) {
                        temp.insert(k);
                    }
                }
            }
            temp.erase(i);
        }
        tovisit = temp;
        ans++;
    }

    cout << -1; // 불가능한 경우
}