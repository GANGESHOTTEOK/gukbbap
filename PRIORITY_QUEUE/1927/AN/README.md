
# 백준 1927번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 3월 27일

---

### 접근 방식


### 소스코드
- 메모리 : 2912KB
- 시간 : 16ms
```c++
#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL);ios::sync_with_stdio(false);cout.tie(NULL);
    int N;
    cin >> N;
    priority_queue< int,vector<int>, greater<int> > pq;
    for(int i=0; i<N; i++) {
        int x;
        cin >> x;
        if(x) pq.push(x);
        else {
            if(pq.empty()) {
                cout << "0\n";
                continue;
            }
            cout << pq.top() << "\n";
            pq.pop();
        }
    }
}
```
