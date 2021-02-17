
# 백준 1021번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 2월 17일

---

### 접근 방식
- 

### 소스코드
- 메모리 : 2016KB
- 시간 : 0ms
```c++
#include <bits/stdc++.h>
using namespace std;
int N, M, x, cnt=0;
deque<int> dq;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M;
    for(int i=1; i<=N; i++) dq.push_back(i);
    for(int i=0; i<M; i++) {
        cin >> x;
        deque<int>::iterator iter = find(dq.begin(), dq.end(), x);
        int left = iter-dq.begin();
        if(left<=dq.size()/2) {
            for(int j=0; j<left; j++) {
                cnt++;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            for(int j=0; j<dq.size()-left; j++) {
                cnt++;
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        dq.pop_front();
    }
    cout << cnt;
}
```