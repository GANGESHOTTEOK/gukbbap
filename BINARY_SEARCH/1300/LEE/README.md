
# 백준 1300번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 03월 22일 22시 23분

---
### 메모리 및 시간

- 메모리 : 2016KB
- 시간 : 12ms

---

### 접근 방식
```cpp
#include <iostream>
#include <cmath>

using namespace std;

int N, K;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    
    int minVal = 1;
    int maxVal = K;
    int answer = 0;
    while(minVal <= maxVal) {
        int midVal = (minVal + maxVal) / 2;
        int count = 0;
        for (int i = 1; i <= N; i++) count += min(N, midVal / i);
        if (count >= K) {
            answer = midVal;
            maxVal = midVal - 1;
        }
        else minVal = midVal + 1;
        
    }
    cout << answer << endl;
    return 0;
}


```




