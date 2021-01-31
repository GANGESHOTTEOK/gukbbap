
# 백준 2579번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 01월 25일 20시 18분

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
#include <cmath>
#define FOR(a, n) for (int i = a; i < n; i++)
using namespace std;

vector <int> stair;
vector <int> maxStair;

int main(void) {
    int n; cin >> n;
    stair = vector <int>(n, 0);
    maxStair = vector <int>(n, 0);
    FOR(0, n) cin >> stair[i];
    maxStair[0] = stair[0];
    maxStair[1] = stair[1] + stair[0];
    maxStair[2] = max(stair[0] + stair[2], stair[1] + stair[2]);
    FOR(3, n) {
        maxStair[i] = max(maxStair[i - 2] + stair[i], maxStair[i - 3] + stair[i - 1] + stair[i]);
    }
    
    cout << maxStair[n - 1];
    
    return 0;
}


```




