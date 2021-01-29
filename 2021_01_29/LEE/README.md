
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

int main(void) {
    int n; cin >> n;
    vector <int> numList(n, 0);
    vector <int> dp(n, 1);
    for (int i = 0; i < n; i++) cin >> numList[i];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (numList[i] > numList[j]) {
                if (dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
            }
        }
    }
    
    int ans = dp[0];
    for (int i = 0; i < n; i++) ans = ans < dp[i] ? dp[i] : ans;
    cout << ans << endl;
    
    
    return 0;
}



```




