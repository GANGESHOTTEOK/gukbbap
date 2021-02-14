
# 백준 10773번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 02월 12일 23시 51분

---
### 메모리 및 시간

- 메모리 : 3564KB
- 시간 : 24ms

---

### 접근 방식
```cpp
#include <iostream>
#include <vector>

using namespace std;

vector <long long int> num;
int n, t;
int long long sum = 0;
int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t) num.push_back(t);
        else num.pop_back();
    }
    for (auto n: num) sum += n;
    cout << sum << endl;
    return 0;
}



```





