
# 백준 9012번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 2월 13일 21시 11분

---

### 접근 방식
- 

### 소스코드
- 메모리 : 2020KB
- 시간 : 4ms
```c++
#include <bits/stdc++.h>
using namespace std;
int T;
string sentence;
int isVPS(string s) {
    stack<int> ps;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='(') ps.push(1);
        else {
            if(ps.empty()) return 0;
            else ps.pop();
        }
    }
    if(ps.empty()) return 1;
    else return 0;
}
int main() {
    cin >> T;
    for(int i=0; i<T; i++) {
        cin >> sentence;
        if(!isVPS(sentence)) cout << "NO\n";
        else cout << "YES\n";
    }
}
```