#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int C;
int seq[50][100];
int length[50];
int quant[50];
int cache[100][100][10];

int getErrorSum(int* seq, int start, int end) {
    int sum = 0;
    for(int i = start; i <= end; i++) sum += seq[i];
    int mean = round((float) sum / (float) (end - start + 1));
    int errorsum = 0;
    for(int i = start; i <= end; i++) errorsum += (mean - seq[i]) * (mean - seq[i]);
    return errorsum;
}


int quantize(int* sequence, int quant, int length, int start, int end) {
    if(length <= quant) return 0;
    if(cache[start][end][quant-1] != -1) return cache[start][end][quant-1];
    int minimum = getErrorSum(sequence, start, end);
    if(quant == 1) {
        cache[start][end][0] = minimum;
        return minimum;
    }
    for(int i = start; i <= end - quant + 1; i++) {
        int error = getErrorSum(sequence, start, i) + quantize(sequence, quant-1, length-(i-start+1), i+1, end);
        if(error < minimum) minimum = error;
    }
    cache[start][end][quant-1] = minimum;
    return minimum;
}

void initialize() {
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 100; j++)
            for(int k = 0; k < 10; k++)
                cache[i][j][k] = -1;
}

int main() {
    cin >> C;
    for(int i = 0; i < C; i++) {
        cin >> length[i];
        cin >> quant[i];
        for(int j = 0; j < length[i]; j++){
            cin >> seq[i][j];
        }
        sort(seq[i], seq[i] + length[i]);
    }

    for(int i = 0; i < C; i++) {
        initialize();
        cout << quantize(seq[i], quant[i], length[i], 0, length[i]-1) << endl;
    }

    return 0;
}