
# 백준 11399번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 2월 8일 9시 45분 

---

### 접근 방식
- greedy

### 소스코드
- 메모리 : 2020KB
- 시간 : 0ms
```c++
#include <bits/stdc++.h>
using namespace std;

int N, P[1001], sum=0;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) cin >> P[i];

    sort(P, P+N);

    for(int i=0; i<N; i++) sum += P[i]*(N-i);
    
    cout << sum;
}
```
