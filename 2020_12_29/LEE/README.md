
# 백준 2231번 문제

---

### 문제 해결 날짜 및 시간

- 2020년 12월 29일 20시 12분

---

### 접근 방식
생성자인지 확인하는 범위를 `1`부터 `num + 1`로 설정함
```c++
#include <iostream>
using namespace std;

int getGenerateNum(int num) {
    int result = num;
    while (num > 0) {
        result += num % 10;
        num /= 10;
    }
    return result;
}

int main(void) {
    int num = 0;
    cin >> num;
    int i;
    for (i = 1; i < num + 1; i++) {
        int generateNum = getGenerateNum(i);
        if (num == generateNum) {
            cout << i;
            break;
        }
    }
    if (i == num + 1) cout << 0;
    return 0;
}


```




