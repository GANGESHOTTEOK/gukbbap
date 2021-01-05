
# 백준 10989번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 01월 05일 19시 32분

---
### 메모리 및 시간

- 메모리 : 2016KB
- 시간 : 1544ms

---

### 접근 방식
```cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int num; cin >> num;
    int list[10000] = {0, };
    for (int i = 0; i < num; i++) {
        int temp; cin >> temp;
        list[temp - 1] += 1;
    }
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < list[i]; j++) {
            cout << i + 1 << '\n';
        }
    }
    return 0;
}


```
`ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);`  
구글에서 찾아보니 C언어의 `scanf()`, `printf()` 함수가 속도가 빠르며, C++의 `cout`, `cin`은  
속도가 느리다고 한다. 그래서 상기 코드를 사용하면 C++에서 출력 속도를 높일 수 있다.

그리고 `std::endl`은 개행문자인 `\n`보다 느리다고 한다. 역시 수정해주니 속도가 높아졌다.




