
# 백준 1912번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 2월 3일 1시 2분

---

### 접근 방식


### 소스코드
- 메모리 : 3580KB
- 시간 : 8ms
```c++
#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[100001], A[100001];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> A[i];
    }

    dp[0] = A[0];
    long long Max = dp[0];

    for(int i=1; i<n; i++) {
        dp[i] = max(dp[i-1]+A[i], A[i]);
        Max = max(dp[i], Max);
    }

    cout << Max;
}
```
