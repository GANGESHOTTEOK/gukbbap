
# 백준 1463번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 01월 26일 22시 48분

---
### 메모리 및 시간

- 메모리 : 5924KB
- 시간 : 4ms

---

### 접근 방식
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n; cin >> n;
    vector <int> dp(n + 1, 0);
    dp[1] = 0; dp[2] = 1; dp[3] = 1;
    for (int i = 4; i <= n; i++) {
        if (i % 3 == 0 && i % 2 == 0) {
            if (dp[i / 3] <= dp[i / 2] && dp[i / 3] <= dp[i - 1]) dp[i] = dp[i / 3] + 1;
            else if (dp[i / 2] <= dp[i / 3] && dp[i / 2] <= dp[i - 1]) dp[i] = dp[i / 2] + 1;
            else dp[i] = dp[i - 1] + 1;
        }
        else if (i % 3 == 0) {
            if (dp[i / 3] <= dp[i - 1]) dp[i] = dp[i / 3] + 1;
            else dp[i] = dp[i - 1] + 1;
        }
        else if (i % 2 == 0) {
            if (dp[i / 2] <= dp[i - 1]) dp[i] = dp[i / 2] + 1;
            else dp[i] = dp[i - 1] + 1;
        }
        else {
            dp[i] = dp[i - 1] + 1;
        }
    }
    cout << dp[n] << endl;
    return 0;
}

```




