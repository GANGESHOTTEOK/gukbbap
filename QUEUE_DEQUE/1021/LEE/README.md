
# 백준 1021번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 02월 21일 19시 42분

---
### 메모리 및 시간

- 메모리 : 2016KB
- 시간 : 0ms

---

### 접근 방식
```cpp
#include <iostream>
#include <deque>

using namespace std;

int main(void) {
    deque<int> dq;
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }
    
    int m;
    cin >> m;
    deque<int> target;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        target.push_back(t);
    }
    
    int ans = 0;
    while(!target.empty()) {
        if (dq[0] == target[0]) {
            target.pop_front();
            dq.pop_front();
        }
        else {
            int i;
            for (i = 0; dq[i] != target[0]; i++) ;
            if (i > dq.size() / 2) {
                while (dq[0] != target[0]) {
                    dq.push_front(dq.back());
                    dq.pop_back();
                    ans++;
                }
            }
            else {
                while (dq[0] != target[0]) {
                    dq.push_back(dq.front());
                    dq.pop_front();
                    ans++;
                }
            }
            dq.pop_front();
            target.pop_front();
        }
    }
    cout << ans;
    return 0;
}
```





