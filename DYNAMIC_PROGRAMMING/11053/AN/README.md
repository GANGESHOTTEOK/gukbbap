
# 백준 11053번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 1월 29일 23시 25분

---

### 접근 방식


### 소스코드
- 메모리 : 2024KB
- 시간 : 0ms
```c++
#include <bits/stdc++.h>

using namespace std;

int N, A[1000], dp[1000]={1,};

int fx(int n) {
    if(dp[n]) return dp[n];
    int M = 0;
    for(int i=n-1; i>=0; i--) {
        if(M<fx(i) && A[i]<A[n]) M = fx(i);
    }
    return dp[n] = M+1;
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    fx(N-1);
    cout << *max_element(dp, dp+N);
}
```
