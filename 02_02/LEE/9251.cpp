#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(void) {
    string a, b;
    cin >> a >> b;
    int ans = 0;
    vector <vector <int>> dp(a.length() + 1, vector <int>(b.length() + 1, 0));
    for (int i = 1; i < a.length() + 1; i++) {
        for (int j = 1; j < b.length() + 1; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (a[i - 1]==b[j - 1]));
            ans = dp[i][j] > ans ? dp[i][j] : ans;
        }
    }
    cout << ans << endl;
    return 0;
}

