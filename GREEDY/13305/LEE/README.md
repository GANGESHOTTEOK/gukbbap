
# 백준 13305번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 02월 10일 23시 20분

---
### 메모리 및 시간

- 메모리 : 3564KB
- 시간 : 96ms

---

### 접근 방식
```cpp
#include <iostream>
#include <vector>
#define MAX_VAL 1000000001
using namespace std;

int n, t;
long long int total = 0, min_price = MAX_VAL;
vector <long int> road;

int main(void) {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> t;
        road.push_back(t);
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> t;
        min_price = t < min_price ? t : min_price;
        total += min_price * road[i];
    }
    cin >> t;
    cout << total << endl;
    return 0;
}

```





