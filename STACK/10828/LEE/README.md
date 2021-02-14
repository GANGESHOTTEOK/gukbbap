
# 백준 10828번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 02월 11일 21시 20분

---
### 메모리 및 시간

- 메모리 : 2020KB
- 시간 : 352ms

---

### 접근 방식
```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
string s;
int d;
vector <int> stack;

int main(void) {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s.compare("push") == 0) {
            cin >> d;
            stack.push_back(d);
        }
        else if (s.compare("pop") == 0) {
            if (stack.size()) {
                cout << stack.back() << endl;
                stack.pop_back();
            }
            else cout << -1 << endl;
        }
        else if (s.compare("size") == 0) {
            cout << stack.size() << endl;
        }
        else if (s.compare("empty") == 0) {
            cout << int(stack.size() == 0) << endl;
        }
        else {
            if (stack.size()) cout << stack.back() << endl;
            else cout << -1 << endl;
        }
    }
    return 0;
}

```





