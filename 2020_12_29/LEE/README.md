
# 백준 2231번 문제

---

### 문제 해결 날짜 및 시간

- 2020년 12월 29일 20시 12분

---

### 접근 방식
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

int getStartIndex(int num) {
    int result = 0;
    for (int i = 1; i < num; i *= 10) {
        result += 9;
    }
    return num - result;
}

int main(void) {
    int num = 0;
    cin >> num;
    int i;
    for (i = getStartIndex(num); i < num; i++) {
        int generateNum = getGenerateNum(i);
        if (num == generateNum) {
            cout << i;
            return 0;
        }
    }
    if (i == num) cout << 0;
    return 0;
}
```
탐색범위를 줄여서 코드의 효율성을 증가 시킴.
만약 `M`자리의 숫자인 `N`이 입력된다면 탐색 시작 범위는 `N - 9 * M`으로 지정하면 된다.




