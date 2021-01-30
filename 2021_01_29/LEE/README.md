
# 백준 11053번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 01월 29일 20시 15분

---
### 메모리 및 시간

- 메모리 : 2016KB
- 시간 : 4ms

---

### 접근 방식
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector <int> n, dp;
int N;

int main() {
    cin >> N;
    n = vector <int>(N, 0);
    dp = vector <int>(N, 1);
    for (int i = 0; i < N; i++) cin >> n[i];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (n[i] > n[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl; 
    return 0;
}



```




