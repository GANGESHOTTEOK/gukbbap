
# 백준 18258번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 2월 17일

---

### 접근 방식
- 

### 소스코드
- 메모리 : 8412KB
- 시간 : 424ms
```c++
#include <bits/stdc++.h>
using namespace std;
int N, k;
queue<int> q;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) {
        string token;
        cin >> token;
        if(!token.compare("push")) {
            cin >> k;
            q.push(k);
        }
        else if(!token.compare("size")) cout << q.size() << "\n";
        else if(!token.compare("empty")) cout << q.empty() << "\n";
        else {
            if(q.empty()) cout << "-1\n";
            else {
                if(!token.compare("front") || !token.compare("pop")) cout << q.front() << "\n";
                else if(!token.compare("back")) cout << q.back() << "\n";
                if(!token.compare("pop")) q.pop();
            }
        }
    }
}
```