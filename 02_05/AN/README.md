
# 백준 11047번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 2월 5일 14시 13분

---

### 접근 방식
- greedy

### 소스코드
- 메모리 : 2016KB
- 시간 : 0ms
```c++
#include <bits/stdc++.h>

using namespace std;

int N, K, A[10], sum=0, cnt=0;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N >> K;
    for(int i=0; i<N; i++) cin >> A[i];

    for(int i=N-1; i>-1; i--) {
        if(A[i]>K) continue;
        int n = K/A[i];
        cnt += n;
        K -= A[i]*n;
        if(!K) break;
    }

    cout << cnt;
}
```
