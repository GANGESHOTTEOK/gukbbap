
# 백준 2156번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 1월 28일 15시 53분

---

### 접근 방식
- 3잔 연속 마실 수 없다.
- `n`번째 잔을 마시려면 `n-2`번째 와인을 마신 후이거나 n-3번쨰 와인과 n-1번째 와인을 마신 후여야 한다. 즉, `f(n) = max(wine[n-1]+fx(n-3), fx(n-2)) + wine[n]` 이다.
- `n`번쨰 잔을 마시지 않을 경우 `n`번째에 해당하는 최댓값은 `f(n-1)`이 된다.

### 소스코드
- 메모리 : 2440KB
- 시간 : 4ms
```c++
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
```
- `dp[n]` : `n`번째 와인에 해당하는 와인양의 최댓값