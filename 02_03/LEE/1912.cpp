#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> numList;
vector <int> dp;

int main(void) {
    int n; cin >> n;
    numList = vector <int>(n, 0);
    dp = vector <int>(n, 0);
    for (int i = 0; i < n; i++) cin >> numList[i];
    dp[0] = numList[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(numList[i], dp[i - 1] + numList[i]);
    }
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}

