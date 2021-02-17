
# 백준 2164번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 02월 18일 00시 58분

---
### 메모리 및 시간

- 메모리 : 4152KB
- 시간 : 4ms

---

### 접근 방식
```cpp
#include <iostream>
#include <queue>

using namespace std;

int n;
queue <int> num;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++) num.push(i);
    while(num.size() > 1) {
        num.pop();
        num.push(num.front());
        num.pop();
    }
    cout << num.front() << "\n";
}



```





