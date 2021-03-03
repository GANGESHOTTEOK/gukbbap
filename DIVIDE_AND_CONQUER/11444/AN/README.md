
# 백준 11444번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 2월 25일 21시 45분

---

### 접근 방식
- F(2n-1) = F(n)^2 + F(n-1)^2, F(2n) = (2F(n-1)+F(n))F(n) 임을 이용한다.

### 소스코드
- 메모리 : 2020KB
- 시간 : 0ms
```c++
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
```