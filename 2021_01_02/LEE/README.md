
# 백준 1436번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 01월 02일 17시 52분

---

### 접근 방식
```c++
#include <iostream>
#define MAX_SIZE 2002

using namespace std;

int main(void) {
    int list[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) list[i] = 0;
    int size = 0;
    cin >> size;
    for (int i = 0; i < size; i++) {
        int input = 0;
        cin >> input;
        list[input + 1001] = 1;
    }
    for (int i = 0; i < MAX_SIZE; i++) {
        if (list[i]) cout << i - 1001 << endl;
    }
    return 0;
}

```
문제에서 중복되는 숫자는 없고, 절댓값이 1000이하인 숫자들로만 입력이 구성된다고 해서 일반적인 정렬이 아닌 다른 방법으로 풀었다.
사이즈가 `2002`인 배열을 선언하여 값을 모두 0으로 초기화하고, 숫자가 `n`이 입력된다면 `list[n + 1001]`의 값을 1로 바꾸어 주었다. 그리고 마지막에 `list`의 값이 1인 숫자만  출력하면 정답.




