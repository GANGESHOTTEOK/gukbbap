#include <bits/stdc++.h>
using namespace std;
int N, dp[10001], wine[10001];
int fx(int n) {
    if(n<=0) return 0;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = max(max(wine[n-1]+fx(n-3), fx(n-2)) + wine[n], fx(n-1));
}
int main() {
    cin >> N;
    memset(dp, -1, sizeof(dp));
    for(int i=1; i<=N; i++) cin >> wine[i];
    cout << fx(N);
}