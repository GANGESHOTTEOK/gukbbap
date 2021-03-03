
# 백준 11401번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 2월 23일 23시 20분

---

### 접근 방식
- 페르마 소정리의 역원을 이용하였다.

### 소스코드
- 메모리 : 2016KB
- 시간 : 36ms
```c++
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
```