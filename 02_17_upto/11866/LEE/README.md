
# 백준 11866번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 02월 18일 01시 06분

---
### 메모리 및 시간

- 메모리 : 2016KB
- 시간 : 0ms

---

### 접근 방식
```cpp
#include <iostream>
#include <queue>

using namespace std;

int n, k, idx = 1;
queue <int> people;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) people.push(i);
    
    cout << "<";
    while(people.size() > 1) {
        if (idx == k) {
            cout << people.front() << ", ";
            people.pop();
            idx = 0;
        }
        else {
            people.push(people.front());
            people.pop();
        }
        idx++;
    }
    cout << people.front() << ">";
    return 0;
}



```





