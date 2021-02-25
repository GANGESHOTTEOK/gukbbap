
# 백준 10830번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 02월 25일 00시 44분

---
### 메모리 및 시간

- 메모리 : 2016KB
- 시간 : 0ms

---

### 접근 방식
```cpp
#include <iostream>

using namespace std;

long int n, b;
int arr[5][5];
int ans[5][5];
int temp[5][5];

void matrixSquare(int arr1[5][5], int arr2[5][5]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < n; k++) {
                temp[i][j] += (arr1[i][k] * arr2[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) ans[i][j] = temp[i][j] % 1000;
    }
}

void divideAndConquer(long int n) {
    if (n == 1) return ;
    if (n == 2) {
        matrixSquare(ans, ans);
        return ;
    }
    divideAndConquer(n / 2);
    matrixSquare(ans, ans);
    if (n % 2 == 1) matrixSquare(arr, ans);
}

int main(void) {
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            ans[i][j] = arr[i][j] % 1000;
        }
    }
    divideAndConquer(b);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}


```





