
# 백준 18258번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 02월 18일 00시 46분

---
### 메모리 및 시간

- 메모리 : 8412KB
- 시간 : 392ms

---

### 접근 방식
```cpp
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, t;
queue <int> num;
string input;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (input == "push") {
            cin >> t;
            num.push(t);
        }
        else if (input == "pop") {
            if (num.empty()) cout << "-1\n";
            else {
                cout << num.front() << "\n";
                num.pop();
            }
        }
        else if (input == "size") {
            cout << num.size() << "\n";
        }
        else if (input == "empty") {
            cout << num.empty() << "\n";
        }
        else if (input == "front") {
            if (num.empty()) cout << "-1\n";
            else cout << num.front() << "\n";
        }
        else if (input == "back") {
            if (num.empty()) cout << "-1\n";
            else cout << num.back() << "\n";
        }
    }
}

```





