
# 백준 2164번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 2월 17일

---

### 접근 방식
- 

### 소스코드
- 메모리 : 4036KB
- 시간 : 4ms
```c++
#include <bits/stdc++.h>
using namespace std;
int N;
queue<int> q;
int main() {
    cin >> N;
    for(int i=1; i<=N; i++) q.push(i);
    while(q.size()!=1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front();
}
```