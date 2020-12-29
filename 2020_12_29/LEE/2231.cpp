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

int main(void) {
    int num = 0;
    cin >> num;
    int i;
    for (i = 1; i < num + 1; i++) {
        int generateNum = getGenerateNum(i);
        if (num == generateNum) {
            cout << i;
            break;
        }
    }
    if (i == num + 1) cout << 0;
    return 0;
}

