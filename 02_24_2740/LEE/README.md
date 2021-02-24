
# 백준 10830번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 02월 23일 23시 02분

---
### 메모리 및 시간

- 메모리 : 2016KB
- 시간 : 116ms

---

### 접근 방식
```cpp
#include <iostream>

using namespace std;

int n, b;
int ** arr;
int ** ans;

void matrixSquare(int ** arr1, int ** arr2) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ans[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

void divideAndConquer(int n) {
    if (n == 1) return ;
    if (n == 2) {
        matrixSquare(ans, ans);
    }
    else {
        matrixSquare(ans, ans);
        divideAndConquer(n / 2);
    }
}

int main(void) {
    cin >> n;
    arr = new int *[n];
    ans = new int *[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        ans[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            ans[i][j] = arr[i][j];
        }
    }
    if (b % 2) {
        divideAndConquer(b);
    }
    else {
        
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << ans[i][j] << " ";
        cout << endl;
    }
    
    
    return 0;
}




```





