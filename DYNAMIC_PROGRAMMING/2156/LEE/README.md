
# 백준 2156번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 01월 28일 20시 15분

---
### 메모리 및 시간

- 메모리 : 2016KB
- 시간 : 4ms

---

### 접근 방식
```cpp
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main(void) {
    int n; cin >> n;
    vector <int> wine(n, 0);
    vector <int> dp(n, 0);
    for (int i = 0; i < n; i++) cin >> wine[i];
    dp[0] = wine[0];
    if (n < 3) {
        if (n == 1) cout << wine[0] << endl;
        else cout << wine[0] + wine[1] << endl;
        return 0;
    }
    dp[1] = wine[0] + wine[1];
    dp[2] = max(wine[0] + wine[2], wine[1] + wine[2]);
    dp[2] = max(dp[2], dp[1]);
    
    for (int i = 3; i < n; i++) {
        if (wine[i]) {
            dp[i] = max(dp[i - 3] + wine[i - 1] + wine[i],
                        dp[i - 2] + wine[i]);
            dp[i] = max(dp[i], dp[i - 1]);
        }
        else dp[i] = dp[i - 1];
    }
    int result = dp[0];
    for (int i = 0; i < n; i++) {
        if (result < dp[i]) result = dp[i];
    }
    cout << result << endl;
    return 0;
}

```




