
# 백준 10816번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 3월 14일 15시 14분

---

### 접근 방식
- 

### 소스코드
- 메모리 : 25252KB
- 시간 : 656ms
```c++
#include <bits/stdc++.h>
using namespace std;
int N, M, num;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    map<int,int> cnt;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        if(!cnt.count(temp)) cnt[temp] = 1;
        else cnt[temp]++;
    }
    cin >> M;
    for(int i=0; i<M; i++) {
        cin >> num;
        if(!cnt.count(num)) cout << "0 ";
        else cout << cnt[num] << " ";
    }
}
```