
# 백준 9012번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 02월 13일 23시 51분

---
### 메모리 및 시간

- 메모리 : 2016KB
- 시간 : 4ms

---

### 접근 방식
```cpp
#include <iostream>
#include <stack>

using namespace std;

int n;

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        stack <char> s;
        char string[50]; cin >> string;
        for (char *c = string; *c; c++) {
            if (*c == '(') s.push(*c);
            else {
                if (s.size() == 0) s.push(*c);
                else if (s.top() == '(')s.pop();
            }
        }
        if (s.size() != 0) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}

```





