#include <iostream>
#include <string>

using namespace std;

string input;
int result = 0;
int num = 0, stack_num = 0;
bool minusFlag = false;
int main(void) {
    cin >> input;
    for (char c: input) {
        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
        }
        else if (c == '-') {
            if (minusFlag) result -= num;
            else result += num;
            minusFlag = true;
            num = 0;
        }
        else {
            if (minusFlag) result -= num;
            else result += num;
            num = 0;
        }
    }
    if (minusFlag) result -= num;
    else result += num;
    cout << result << endl;
    return 0;
}
