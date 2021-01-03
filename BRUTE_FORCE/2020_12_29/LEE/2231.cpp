#include <iostream>

using namespace std;

int getGenerateNum(int num) {
    int result = num;
    while (num > 0) {
        result += num % 10;
        num /= 10;
    }
    return result;
}

int getStartIndex(int num) {
    int result = 0;
    for (int i = 1; i < num; i *= 10) {
        result += 9;
    }
    return num - result;
}

int main(void) {
    int num = 0;
    cin >> num;
    int i;
    for (i = getStartIndex(num); i < num; i++) {
        int generateNum = getGenerateNum(i);
        if (num == generateNum) {
            cout << i;
            return 0;
        }
    }
    if (i == num) cout << 0;
    return 0;
}

