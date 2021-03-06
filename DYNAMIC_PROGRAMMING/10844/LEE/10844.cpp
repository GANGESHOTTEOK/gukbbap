#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void) {
    int n; cin >> n;
    vector <long long int> count = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    for (int i = 1; i < n; i++) {
        vector <long long int> temp(10, 0);
        for (int j = 0; j < 10; j++) {
            if (j == 9) {
                temp[8] += count[9] % 1000000000;
            }
            else if (j == 0) {
                temp[1] += count[0] % 1000000000;
            }
            else {
                temp[j - 1] += count[j] % 1000000000;
                temp[j + 1] += count[j] % 1000000000;
                temp[j - 1] %= 1000000000;
                temp[j + 1] %= 1000000000;
            }
        }
        for (int j = 0; j < 10; j++) count[j] = temp[j] % 1000000000;
    }
    int result = 0;
    for (int i = 0; i < 10; i++) {
        result += count[i] % 1000000000;
        result %= 1000000000;
    }
    cout << result % 1000000000 << endl;
    return 0;
}
