//
// Created by 진성찬 on 2022/01/07.
//
#include <iostream>
int case_number, student_number, friend_number;

int picnic(bool taken[10], int friends[10][10]){
    int minnum = -1;
    for (int i = 0; i<student_number; i++)
        if(!taken[i]) {
            minnum = i;
            break;
        }

    if (minnum == -1) return 1;

    int ret = 0;
    for (int i = minnum+1; i<student_number; i++){
        if(!taken[i] && friends[minnum][i] == 1){
            taken[i] = true;
            taken[minnum] = true;
            ret += picnic(taken,friends);
            taken[i] = false;
            taken[minnum] = false;
        }
    }

    return ret;
}
int main(){
    std::cin >> case_number;
    int *answer = new int[case_number];

    for(int T = 0; T < case_number; T++){
        int friends[10][10] = {0};
        std::cin >> student_number >> friend_number;
        bool taken[10] = {false};
        int *friend_list = new int[2 * friend_number];
        for(int i = 0; i< 2 * friend_number; i++) {
            std::cin >> friend_list[i];
        }

        for(int i = 0; i< friend_number; i++){
            int a = friend_list[2*i];
            int b = friend_list[2*i+1];
            friends[a][b] = 1;
            friends[b][a] = 1;
        }
        delete[] friend_list;
        answer[T] = picnic(taken,friends);
    }

    for (int i = 0; i < case_number; i++) {
        std::cout << answer[i];
        if(i < case_number - 1) std::cout << std::endl;
    }

    delete[] answer;
}