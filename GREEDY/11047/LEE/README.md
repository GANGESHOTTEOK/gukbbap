
# 백준 11047번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 02월 05일 23시 51분

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

int n, k;
vector <int> coinList;
int main(void) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (t < k) coinList.push_back(t);
    }
    n = (int) coinList.size();
    int count = 0;
    int i = n - 1;
    while(k > 0 && i >= 0) {
        count += k / coinList[i];
        k %= coinList[i];
        i--;
    }
    cout << count << endl;
    return 0;
}


```





