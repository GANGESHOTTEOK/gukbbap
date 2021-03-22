
# 백준 2110번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 3월 22일

---

### 접근 방식
- 
### 소스코드
- 메모리 : 2408KB
- 시간 : 68ms
```c++
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,C;
    cin >> N >> C;
    vector<int> X(N);
    for(int i=0; i<N; i++) cin >> X[i];
    sort(X.begin(), X.end());
    int left=1, right=X.back(), maxDist=0;
    while(left<=right) {
        int mid = (left+right)/2;
        int cnt=1, xl=X.front();
        for(auto xr:X) {
            if(xr-xl >= mid) {
                xl = xr;
                cnt++;
            }
        }
        if(cnt<C) right=mid-1;
        else {
            maxDist=mid;
            left=mid+1;
        }
    }
    cout << maxDist;
}
```