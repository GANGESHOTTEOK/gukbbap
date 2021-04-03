
# 백준 12015번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 03월 28일 21시 57분

---
### 메모리 및 시간

- 메모리 : 2152KB
- 시간 : 152ms

---

### 접근 방식
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, T;
vector <int> num(1);
int main(void) {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> num[0];
    for (int i = 1; i < N; i++) {
        cin >> T;
        if (T > num.back()) num.push_back(T);
        else num[lower_bound(num.begin(), num.end(), T) - num.begin()] = T;
    }
    cout << num.size() << endl;
    return 0;
}




```





