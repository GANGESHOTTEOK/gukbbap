
# 백준 2565번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 02월 01일 23시 36분

---
### 메모리 및 시간

- 메모리 : 2016KB
- 시간 : 0ms

---

### 접근 방식
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N; cin >> N;
    vector <int> wire(501, 0);
    vector <int> dp(501, 0);
    int max_val = 1;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        wire[a] = b; dp[a] = 1;
        max_val = a > max_val ? a : max_val;
    }
    
    for (int i = 1; i <= max_val; i++) {
        for (int j = 1; j < i; j++) {
            if (wire[i] > wire[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << N - *max_element(dp.begin(), dp.end());
    return 0;
}



```





