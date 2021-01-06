#include <iostream>
#include <cmath>
#define FOR(a,n) for (int i = 0; i < (n); i++)
#define SIZE 8001
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int num = 0, mean = 0, median = 0, mode = 0, range = 0;
    int sum = 0, mid_range = 0, max_val = SIZE * (-1), min_val = SIZE, mode_cnt = 0, mode_check = 0;
    cin >> num;
    int numList[SIZE] = {0, };
    FOR(i, num) {
        int temp; cin >> temp; sum += temp;
        if (temp > max_val) max_val = temp;
        if (temp < min_val) min_val = temp;
        numList[temp + 4000]++;
    }
    
    mean = round((float) sum / (float) num);
    range = max_val - min_val;
    FOR(i, SIZE) {
        if (mode_cnt <= numList[i]) {
            mode = i - 4000; mode_cnt = numList[i];
        }
    }
    FOR(i, SIZE) {
        if (numList[i] == mode_cnt) mode_check++;
        if (mode_check == 2) {
            mode = i - 4000; break;
        }
    }
    
    mid_range = num / 2 + 1;
    for(int i = 1; i < SIZE; i++) numList[i] += numList[i - 1];
    FOR(i, SIZE) {
        if (mid_range <= numList[i]) {
            median = i - 4000;
            break;
        }
    }
    
    
    cout << mean << "\n" << median << "\n" << mode << "\n" << range << "\n";
    return 0;
}

