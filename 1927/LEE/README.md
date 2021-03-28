
# 백준 1927번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 03월 28일 21시 57분

---
### 메모리 및 시간

- 메모리 : 2912KB
- 시간 : 12ms

---

### 접근 방식
```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, t;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
        cin >> t;
        if (t == 0) {
            if (pq.size() == 0) cout << "0\n";
            else  {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else pq.push(t);
    }
    return 0;
}




```





