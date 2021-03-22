
# 백준 1300번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 3월 22일

---

### 접근 방식
- 

### 소스코드
- 메모리 : 2016KB
- 시간 : 12ms
```c++
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,k;
    cin >> N >> k;
    int left=1, right=k, ans=0;
    while(left<=right) {
        int mid=(left+right)/2;
        int cnt=0;
        for(int i=1; i<=N; i++) cnt += min(mid/i,N);
        if(cnt<k) left = mid+1;
        else {
            right = mid-1;
            ans = mid;
        }
    }
    cout << ans;
}
```