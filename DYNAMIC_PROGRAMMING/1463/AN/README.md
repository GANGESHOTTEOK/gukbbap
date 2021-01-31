
# 백준 1463번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 1월 26일 22시 30분

---

### 접근 방식
- 동적계획법 사용.

### 소스코드
- 메모리 : 37052KB
- 시간 : 40ms
```c++
#include <bits/stdc++.h>

using namespace std;

int N, dp[1000001];

int fx(int n) {
    if(n==1) return 0;
    if(n==2 || n==3) return 1;

    if(dp[n]) return dp[n];

    if(n%2 && n%3) return dp[n] = fx(n-1) + 1;                  // 2와 3의 공배수가 아닐 때
    if(n%2) return dp[n] = min(fx(n-1), fx(n/3)) + 1;           // 2의 배수가 아닐 때
    if(n%3) return dp[n] = min(fx(n-1), fx(n/2)) + 1;           // 3의 배수가 아닐 때
    return dp[n] = min(fx(n-1), min(fx(n/2), fx(n/3))) + 1;     // 2와 3의 공배수일 때
}

int main() {
    cin >> N;
    cout << fx(N);
}
```
