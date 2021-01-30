#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector <int> n, dp;
int N;

int main() {
    cin >> N;
    n = vector <int>(N, 0);
    dp = vector <int>(N, 1);
    for (int i = 0; i < N; i++) cin >> n[i];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (n[i] > n[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}

