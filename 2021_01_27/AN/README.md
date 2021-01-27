
# 백준 10844번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 1월 26일 16시 50분

---

### 접근 방식
- `n`자리 수 계단 수의 개수는 `n-1`자리의 계단 수에 영향을 받는다.

### 소스코드
- 메모리 : 2024KB
- 시간 : 0ms
```c++
#include <bits/stdc++.h>

using namespace std;

#define m 1000000000
int N;
long long dp[101][10], sum=0;

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
    // dp를 -1로 초기화.
    memset(dp,-1,sizeof(dp));
    dp[1][0] = 0;
    for(int i=1; i<10; i++) dp[1][i] = 1;

    for(int i=0; i<10; i++) sum += fx(N,i);
    cout << sum%m;
}
```
- `dp[n][k]` : `n`자리 계단 수에서 끝자리가 `k`인 수의 개수
- `long long fx(int n, int k)` : `dp[n][k]`의 값을 반환