
# 백준 10828번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 2월 11일 1시 36분

---

### 접근 방식
- 

### 소스코드
- 메모리 : 2020KB
- 시간 : 328ms
```c++
#include <bits/stdc++.h>
using namespace std;

int N, k;
stack<int> s;

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        string cmd;
        cin >> cmd;

        if(!cmd.compare("push")) { // push k
            cin >> k;
            s.push(k);
        }
        else if(!cmd.compare("size")) cout << s.size() << "\n";         // size
        else if(!cmd.compare("empty")) cout << s.empty() << "\n";       // empty  
        else {      // pop, top
            if(s.empty()) cout << "-1\n";   // if stack is empty
            else {
                cout << s.top() << "\n";
                if(!cmd.compare("pop")) s.pop();
            }
        }
    }
}
```
