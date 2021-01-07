#include <iostream>

using namespace std;

bool isTerminateNum(int num) {
    bool checkContinue = false;
    int count = 0;
    
    while (num > 0) {
        if (num % 10 == 6) {
            checkContinue = true;
            count += 1;
        }
        else {
            checkContinue = false;
            count = 0;
        }
        num /= 10;
        if (count == 3) return true;
    }
    
    return false;
}

int main(void) {
    int num;
    cin >> num;
    int count = 0;
    for (int i = 666; count < num; i++) {
        if (isTerminateNum(i)) count += 1;
        if (count == num) cout << i;
    }
    return 0;
}
