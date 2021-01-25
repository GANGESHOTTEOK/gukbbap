
# 백준 1003번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 01월 20일 21시 33분

---
### 메모리 및 시간

- 메모리 : 5924KB
- 시간 : 4ms

---

### 접근 방식
```cpp
#include <iostream>

using namespace std;

int num_list[1000001] = {0, };

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    num_list[1] = 1;
    num_list[2] = 2;
    for (int i = 3; i <= n; i++) {
        num_list[i] = (num_list[i - 1] + num_list[i - 2]) % 15746;
        
    }
    cout << num_list[n] << endl;
    return 0;
}



```




