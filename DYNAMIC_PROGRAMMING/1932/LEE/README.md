
# 백준 1932번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 01월 23일 20시 43분

---
### 메모리 및 시간

- 메모리 : 3968KB
- 시간 : 12ms

---

### 접근 방식
```cpp
#include <iostream>
#include <cmath>
using namespace std;

int pyramid[500][500];
int maxPyramid[500][500];

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> pyramid[i][j];
        }
    }
    
    maxPyramid[0][0] = pyramid[0][0];
    for (int i = 1; i < n; i++) {
        maxPyramid[i][0] = maxPyramid[i - 1][0] + pyramid[i][0];
        for (int j = 1; j < i; j++) {
            maxPyramid[i][j] = max(maxPyramid[i - 1][j - 1], maxPyramid[i - 1][j]) + pyramid[i][j];
        }
        maxPyramid[i][i] = maxPyramid[i - 1][i - 1] + pyramid[i][i];
    }
    
    int result = maxPyramid[n - 1][0];
    for (int i = 1; i < n; i++) {
        result = max(result, maxPyramid[n - 1][i]);
    }
    cout << result;
    
    return 0;
}



```




