#include <iostream>

using namespace std;

int n, t;
int timeList[1001] = {0, };

int getTime() {
    int ans = 0;
    int num = n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < timeList[i]; j++) {
            ans += i * num--;
        }
    }
    return ans;
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        timeList[t]++;
    }
    cout << getTime() << endl;
    return 0;
}

