
# 백준 11279번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 3월 27일

---

### 접근 방식


### 소스코드
- 메모리 : 1880KB
- 시간 : 16ms
```c++
#include <bits/stdc++.h>
using namespace std;
int N;
priority_queue<int, vector<int>, less<int>> q;
int main() {
    cin.tie(NULL);ios::sync_with_stdio(false);cout.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) {
        int x;
        cin >> x;
        if(x) q.push(x);
        else if(q.empty()) cout << "0" << "\n";
        else {
            cout << q.top() << "\n";
            q.pop();
        }
    }
}
```
