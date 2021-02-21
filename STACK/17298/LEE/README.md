
# 백준 17928번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 02월 20일 00시 43분

---
### 메모리 및 시간

- 메모리 : 13996KB
- 시간 : 644ms

---

### 접근 방식
```cpp
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
vector <int> arr;
vector <int> ans;
stack <int> s;

void init() {
    cin >> n;
    arr = vector <int>(n);
    ans = vector <int>(n, -1);
    for (int i = 0; i < n; i++) cin >> arr[i];
}

void NGE() {
    for (int i = 0; i < n; i++) {
        while(!s.empty() && arr[s.top()] < arr[i]) {
            ans[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
}

int main(void) {
    init();
    NGE();
    return 0;
}




```





