#include <bits/stdc++.h>
using namespace std;
int N, dp[301]={0,}, w[301];
int fx(int n) {
    if(n<=0) return 0;
    if(n==1) return w[1];
    if(dp[n]) return dp[n];
    return dp[n] = max(fx(n-2), fx(n-3)+w[n-1]) + w[n];
}
int main() {
    cin >> N;
    for(int i=1; i<=N; i++) cin >> w[i];
    cout << fx(N);
}