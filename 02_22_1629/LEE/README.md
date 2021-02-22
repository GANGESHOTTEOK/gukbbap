
# 백준 1629번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 02월 22일 15시 32분

---
### 메모리 및 시간

- 메모리 : 2016KB
- 시간 : 0ms

---

### 접근 방식
```cpp
#include <iostream>

using namespace std;

int divideAndConquer(int a, int b, int c) {
    if (b == 1) return a % c;
    else {
        long int temp = divideAndConquer(a, b / 2, c);
        if (b % 2 != 0) return ((temp * temp) % c * a) % c;
        return (temp * temp) % c;
    }
}

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << divideAndConquer(a, b, c);
    return 0;
}


```





