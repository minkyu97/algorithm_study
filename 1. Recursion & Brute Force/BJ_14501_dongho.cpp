#include <iostream>
#include <string>
#include <vector>

using namespace std;

int sol(int today, int N, int TList[], int PList[]) {
    if(today==N && TList[N-1]==1) return PList[N-1];
    if(today>=N) return 0;


    //std::cout <<PList[today-1]+sol(today+TList[today-1], N, TList, PList) << " " <<  sol(today+1, N, TList, PList) << std::endl;

    if(today + TList[today-1] > N+1) return sol(today + 1, N, TList, PList);
    else return max( PList[today-1]+sol(today+TList[today-1], N, TList, PList), sol(today+1, N, TList, PList));


}

int main() {
    int N;
    scanf("%d", &N);
    int TList[N];
    int PList[N];
    for(int i=0; i<N; i++) {
        scanf("%d", &TList[i]);
        scanf("%d", &PList[i]);
    }

    printf("%d", sol(1, N, TList, PList));

    return 0;;
}




















