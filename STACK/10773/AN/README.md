
# 백준 10773번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 2월 12일 22시 35분

---

### 접근 방식
- 

### 소스코드
- `stack` 사용
- 메모리 : 2412KB
- 시간 : 36ms
```c++
#include <bits/stdc++.h>
using namespace std;
int K, n, sum=0;
stack<int> s;
int main() {
    cin >> K;
    for(int i=0; i<K; i++) {
        cin >> n;
        if(!n) s.pop();
        else s.push(n);
    }
    while(!s.empty()) {
        sum+=s.top();
        s.pop();
    }
    cout << sum;
}
```
### 소스코드
- `vector` 사용
- 메모리 : 2796KB
- 시간 : 28ms
```c++
#include <bits/stdc++.h>
using namespace std;
int N, k;
vector<int> v;
int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> k;
        if(!k) v.pop_back();
        else v.push_back(k);
    }
    cout << accumulate(v.begin(), v.end(), 0);
}
```