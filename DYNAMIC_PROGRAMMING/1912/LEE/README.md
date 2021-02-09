
# 백준 1912번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 02월 03일 00시 07분

---
### 메모리 및 시간

- 메모리 : 2800KB
- 시간 : 28ms

---

### 접근 방식
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> numList;
vector <int> dp;

int main(void) {
    int n; cin >> n;
    numList = vector <int>(n, 0);
    dp = vector <int>(n, 0);
    for (int i = 0; i < n; i++) cin >> numList[i];
    dp[0] = numList[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(numList[i], dp[i - 1] + numList[i]);
    }
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}



```





