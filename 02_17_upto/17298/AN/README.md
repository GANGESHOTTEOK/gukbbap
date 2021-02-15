
# 백준 17298번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 2월 15일

---

### 접근 방식
- 

### 소스코드
- 메모리 : 17298KB
- 시간 : 600ms
```c++
#include <bits/stdc++.h>
using namespace std;
int N;
stack< pair<int,int> > s;
int main() {
    cin >> N;
    int NGE[N];
    for(int i=0; i<N; i++) {
        int k;
        cin >> k;
        if(s.empty()) s.push(make_pair(i,k));
        else {
            while(!s.empty()) {
                if(k<=s.top().second) break;
                else {
                    NGE[s.top().first] = k;
                    s.pop();
                }
            }
            s.push(make_pair(i,k));
        }
    }
    while(!s.empty()) {
        NGE[s.top().first] = -1;
        s.pop();
    }
    for(auto e:NGE) cout << e << " ";
}
```