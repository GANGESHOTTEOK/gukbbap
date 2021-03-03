
# 백준 2740번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 02월 24일 23시 44분

---
### 메모리 및 시간

- 메모리 : 2132KB
- 시간 : 0ms

---

### 접근 방식
```cpp
#include <iostream>

using namespace std;

long int n, m, k;
int a[100][100];
int b[100][100];
int ans[100][100];

void matrixMultiple() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            ans[i][j] = 0;
            for (int l = 0; l < m; l++) {
                ans[i][j] += a[i][l] * b[l][j];
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cin >> m >> k;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> b[i][j];
        }
    }
    matrixMultiple();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) cout << ans[i][j] << " ";
        cout << "\n";
    }
    return 0;
}


```





