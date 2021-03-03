#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define p 1000000007
ll N,K;
ll power(ll x, ll y) {
    if(!y) return 1;
    ll num = power(x,y/2)%p;
    num = (num*num)%p;
    if(y%2) return (num*x)%p;
    else return num%p;
}
ll facto(ll n) {
    ll result=1;
    for(int i=2; i<=n; i++) result = (result*i)%p;
    return result;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N >> K;
    cout << ((facto(N) * power(facto(N-K),p-2) )%p * power(facto(K), p-2))%p;
}