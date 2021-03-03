
# 백준 11444번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 02월 25일 23시 55분

---
### 메모리 및 시간

- 메모리 : 2016KB
- 시간 : 0ms

---

### 접근 방식
```cpp
#include <iostream>

using namespace std;
typedef long long int LL;

LL n;
LL matrix[2][2] = { {1, 1}, {1, 2} };
LL ans[2][2] = { {1, 1}, {1, 2} };
LL temp[2][2];
int divisor = 1000000007;

void multipleMatrix(LL m1[2][2], LL m2[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                temp[i][j] += (m1[i][k] * m2[k][j]) % divisor;
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) ans[i][j] = temp[i][j] % divisor;
    }
}

void divideAndConquer(LL num) {
    if (num < 2) return;
    else if (num == 2) {
        multipleMatrix(ans, ans);
        return ;
    }
    divideAndConquer(num / 2);
    multipleMatrix(ans, ans);
    if (num % 2 == 1) multipleMatrix(ans, matrix);
}

int main(void) {
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    divideAndConquer(n / 2 + n % 2);
    cout << ans[0][!(n % 2)] % divisor << endl;
    return 0;
}



```





