
# 백준 1541번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 02월 09일 23시 20분

---
### 메모리 및 시간

- 메모리 : 2016KB
- 시간 : 0ms

---

### 접근 방식
```cpp
#include <iostream>
#include <string>

using namespace std;

string input;
int result = 0;
int num = 0, stack_num = 0;
bool minusFlag = false;
int main(void) {
    cin >> input;
    for (char c: input) {
        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
        }
        else if (c == '-') {
            if (minusFlag) result -= num;
            else result += num;
            minusFlag = true;
            num = 0;
        }
        else {
            if (minusFlag) result -= num;
            else result += num;
            num = 0;
        }
    }
    if (minusFlag) result -= num;
    else result += num;
    cout << result << endl;
    return 0;
}

```





