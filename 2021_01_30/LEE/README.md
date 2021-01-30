
# 백준 11054번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 01월 30일 22시 24분

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

vector <int> n;
vector <pair <int, int>> dp;
int N;

bool compare(pair <int, int> std, pair<int, int> comp) {
    return std.first + std.second < comp.first + comp.second;
}
int main() {
    cin >> N;
    n = vector <int>(N, 0);
    dp = vector <pair <int, int>>(N, pair<int, int>(1, 1));
    for (int i = 0; i < N; i++) cin >> n[i];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (n[i] > n[j]) dp[i].first = max(dp[i].first, dp[j].first + 1);
        }
    }
    
    for (int i = N - 1; i > -1; i--) {
        for (int j = N - 1; j >= i; j--) {
            if (n[i] > n[j]) dp[i].second = max(dp[i].second, dp[j].second + 1);
        }
    }
    auto max_pos = max_element(dp.begin(), dp.end(), compare);
    cout << max_pos->first + max_pos->second - 1 << endl;
    return 0;
}



```




