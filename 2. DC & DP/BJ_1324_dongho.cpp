#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int LCIS(int arr1[], int arr2[], int n)
{
    //table에 최장 부분 증가 수열의 길이를 저장한다.
    int table[n];
    for (int j=0; j<n; j++)
        table[j] = 0;


    for (int i=0; i<n; i++)
    {
        //현재의 수열의 길이를 초기화한다.
        int current = 0;

        //arr1의 모든 원소에 대해 arr2의 모든 원소를 traverse한다.
        for (int j=0; j<n; j++)
        {
            //두 배열에서 공통된 값을 찾을 경우 현재 수열의 길이에 1을 더해 업데이트한다.
            if (arr1[i] == arr2[j])
                if (current + 1 > table[j])
                    table[j] = current + 1;

            //현재 arr1에서 관측하고 있는 값이 arr2에서 관측하고 있는 값보다 클 때, 실제 공통 수열의 길이가 아니어도 앞으로 같은 값이 등장하면
            //기존 수열의 길이에서 늘리는 것이 가능하므로 현재 수열의 길이를 arr2에서 관측하고 있는 값의 table값으로 한다.
            if (arr1[i] > arr2[j])
                if (table[j] > current)
                    current = table[j];
        }
    }

    int result = 0;
    for (int i=0; i<n; i++)
        if (table[i] > result)
            result = table[i];

    return result;
}


int main(void) {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   int numOfTrash;
   cin >> numOfTrash;

   int* firstArr = new int[numOfTrash]{0};
   int* secondArr = new int[numOfTrash]{0};
   for(int i=0; i<numOfTrash; i++) cin >> firstArr[i];
   for(int i=0; i<numOfTrash; i++) cin >> secondArr[i];

   cout << LCIS(firstArr, secondArr, numOfTrash);

}










