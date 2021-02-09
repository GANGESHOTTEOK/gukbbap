
# 백준 2565번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 2월 1일 13시 12분

---

### 접근 방식


### 소스코드
- 메모리 : 2020KB
- 시간 : 0ms
```c++
#include <bits/stdc++.h>

using namespace std;

int N, A[101], B[501], minIndex=600, maxIndex=0,dp[501];

int fx(int n) {
    if(dp[n]) return dp[n];
    int M = 0;
    for(int i=n-1; i>0; i--) {
        if(B[i]!=0) 
            if(M<fx(i) && B[i]<B[n]) M = fx(i);
    }
    return dp[n] = M+1;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        if(minIndex>temp) minIndex = temp;
        if(maxIndex<temp) maxIndex = temp;
        cin >> B[temp];
    }
    dp[minIndex] = 1;
    fx(maxIndex);
    cout << N-*max_element(dp, dp+501);
}
```
