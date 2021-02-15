
# 백준 1874번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 2월 15일

---

### 접근 방식
- 

### 소스코드
- 메모리 : 2408KB
- 시간 : 60ms
```c++
#include <bits/stdc++.h>
using namespace std;
int n;
stack<int> s;
vector<char> v;
int main() {
    cin >> n;
    int k=0;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        if(k<a) {
            while(k<a) {
                v.push_back('+');
                s.push(++k);
            }
        }
        if(a==s.top()) {
            v.push_back('-');
            s.pop();
        }
        else {
            cout << "NO\n";
            return 0;
        }
    }
    for(auto k:v) cout << k << "\n";
}
```