#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector <int> n;
vector <pair <int, int>> dp;
int N;

bool compare(pair <int, int> std, pair<int, int> comp) {
    return std.first + std.second < comp.first + comp.second;
}
int main() {
    cin >> N;
    n = vector <int>(N, 0);
    dp = vector <pair <int, int>>(N, pair<int, int>(1, 1));
    for (int i = 0; i < N; i++) cin >> n[i];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (n[i] > n[j]) dp[i].first = max(dp[i].first, dp[j].first + 1);
        }
    }
    
    for (int i = N - 1; i > -1; i--) {
        for (int j = N - 1; j >= i; j--) {
            if (n[i] > n[j]) dp[i].second = max(dp[i].second, dp[j].second + 1);
        }
    }
    auto max_pos = max_element(dp.begin(), dp.end(), compare);
    cout << max_pos->first + max_pos->second - 1 << endl;
    return 0;
}

