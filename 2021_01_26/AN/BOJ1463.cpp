#include <bits/stdc++.h>
using namespace std;
int N, dp[1000001];
int fx(int n) {
    if(n==1) return 0;
    if(n==2 || n==3) return 1;
    if(dp[n]) return dp[n];
    if(n%2 && n%3) return dp[n] = fx(n-1) + 1;
    if(n%2) return dp[n] = min(fx(n-1), fx(n/3)) + 1;
    if(n%3) return dp[n] = min(fx(n-1), fx(n/2)) + 1;
    return dp[n] = min(fx(n-1), min(fx(n/2), fx(n/3))) + 1;
            
}
int main() {
    cin >> N;
    cout << fx(N);
}