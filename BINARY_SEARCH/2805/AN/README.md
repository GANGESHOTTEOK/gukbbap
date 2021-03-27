
# 백준 2805번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 3월 22일

---

### 접근 방식
-

### 소스코드
- 메모리 : 5924KB
- 시간 : 668ms
```c++
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> H(N);
    for(int i=0; i<N; i++) cin >> H[i];
    sort(H.begin(), H.end());
    int left=0, right=H.back(), maxHeight=0;
    while(left<=right) {
        int mid = (left+right)/2;
        long long bring = 0;
        for(auto height:H) bring += height>mid ? height-mid : 0;
        if(bring>=M) {
            left=mid+1;
            maxHeight = mid;
        }
        else if(bring < M) right = mid-1;
    }
    cout << maxHeight;
}
```