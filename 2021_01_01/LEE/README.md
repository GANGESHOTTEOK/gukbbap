
# 백준 1436번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 01월 01일 19시 06분

---

### 접근 방식
```c++
#include <iostream>

using namespace std;

bool isTerminateNum(int num) {
    bool checkContinue = false;
    int count = 0;
    
    while (num > 0) {
        if (num % 10 == 6) {
            checkContinue = true;
            count += 1;
        }
        else {
            checkContinue = false;
            count = 0;
        }
        num /= 10;
        if (count == 3) return true;
    }
    
    return false;
}

int main(void) {
    int num;
    cin >> num;
    int count = 0;
    for (int i = 666; count < num; i++) {
        if (isTerminateNum(i)) count += 1;
        if (count == num) cout << i;
    }
    return 0;
}
```
간단하게 숫자를 구성하는 각 숫자들을 확인해서 결과 출력하였음.




