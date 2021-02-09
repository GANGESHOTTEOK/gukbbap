#include <iostream>
#include <vector>

using namespace std;

struct info {
    int weight;
    int value;
};

vector <info> item;
vector <vector <int>> dp;
int n, k;

int main(void) {
    cin >> n >> k;
    item = vector <info>(n + 1);
    dp = vector(n + 1, vector <int>(k + 1, 0));
    for (int i = 1; i <= n; i++) cin >> item[i].weight >> item[i].value;
    
    int maxVal = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (item[i].weight > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j],
                               item[i].value + dp[i - 1][j - item[i].weight]);
            }
            maxVal = maxVal < dp[i][j] ? dp[i][j] : maxVal;
        }
    }
    cout << maxVal << endl;
    return 0;
}

