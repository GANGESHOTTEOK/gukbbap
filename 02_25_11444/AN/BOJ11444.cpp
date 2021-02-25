#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
ll n;
map<ll, ll> dp;
ll fibo(ll k) {
    if(!k) return 0;
    if(k==1 || k==2) return 1;
    if(dp.count(k)) return dp[k];
    if(k%2) return dp[k] = (fibo(k/2)*fibo(k/2)+fibo(k/2+1)*fibo(k/2+1))%mod;
    return dp[k] = ((2*fibo(k/2-1)+fibo(k/2))*fibo(k/2))%mod;
}
int main() {
    cin >> n;
    cout << fibo(n);
}