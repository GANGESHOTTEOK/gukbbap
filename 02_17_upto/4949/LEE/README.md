
# 백준 4949번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 02월 16일 16시 27분

---
### 메모리 및 시간

- 메모리 : 2020KB
- 시간 : 140ms

---

### 접근 방식
```cpp
#include <iostream>
#include <stack>
#include <string>

using namespace std;

string input = "";

void read() { getline(cin, input); }

bool isBalanced() {
    stack <char> brace;
    for (int i = 0; input[i] != '.'; i++) {
        if (input[i] == '(') brace.push('(');
        else if (input[i] == ')') {
            if (brace.empty()) return false;
            else if (brace.top() == '[') return false;
            brace.pop();
        }
        else if (input[i] == '[') brace.push('[');
        else if (input[i] == ']') {
            if (brace.empty()) return false;
            else if (brace.top() == '(') return false;
            brace.pop();
        }
    }
    if (!brace.empty()) return false;
    return true;
}
int main(void) {
    read();
    while (input != ".") {
        if (isBalanced()) cout << "yes\n";
        else cout << "no\n";
        read();
    }
    return 0;
}



```





