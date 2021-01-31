#include <bits/stdc++.h>
using namespace std;
#define m 1000000000
int N;
long long dp[101][10];
long long fx(int n, int k) {
    if(n==1) return dp[1][k];
    if(dp[n][k]!=-1) return dp[n][k];
    if(!k) dp[n][k] = fx(n-1,k+1);
    else if(k==9) dp[n][k] = fx(n-1,k-1);
    else dp[n][k] = fx(n-1,k-1) + fx(n-1,k+1);
    return dp[n][k]%m;
}
int main() {
    cin >> N;
    memset(dp,-1,sizeof(dp));
    dp[1][0] = 0;
    for(int i=1; i<10; i++) dp[1][i] = 1;
    long long sum=0;
    for(int i=0; i<10; i++) sum += fx(N,i);
    cout << sum%m;
}