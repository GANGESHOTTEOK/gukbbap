
# 백준 11866번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 2월 17일

---

### 접근 방식
- 

### 소스코드
- 메모리 : 2024KB
- 시간 : 0ms
```c++
#include <bits/stdc++.h>
using namespace std;
int N, K;
int main() {
    cin >> N >> K;
    queue<int> q1, q2;
    for(int i=1; i<=N; i++) q1.push(i);
    cout << "<";
    for(int i=0; i<N; i++) {
        for(int j=0; j<K-1; j++) {
            if(q1.empty()) {
                q1 = q2;
                while(!q2.empty()) q2.pop();
            }
            q2.push(q1.front());
            q1.pop();
        }
        if(q1.empty()) {
            q1 = q2;
            while(!q2.empty()) q2.pop();
        }
        cout << q1.front();
        q1.pop();
        if(i!=N-1) cout << ", ";
    }
    cout << ">";
}
```