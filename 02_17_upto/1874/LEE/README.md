
# 백준 1874번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 02월 16일 23시 23분

---
### 메모리 및 시간

- 메모리 : 2892KB
- 시간 : 12ms

---

### 접근 방식
```cpp
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int n, t, maxNum;
stack <int> num;
string ans = "";

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    num.push(0);
    maxNum = 0;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (maxNum < t) {
            for (int j = maxNum + 1; j <= t; j++) {
                num.push(j);
                ans += "+\n";
            }
            num.pop();
            ans += "-\n";
            maxNum = t;
        }
        else {
            if (num.top() == t) {
                num.pop();
                ans += "-\n";
            }
            else {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << ans;
    return 0;
}




```





