
# 백준 12865번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 2월 4일 22시 2분

---

### 접근 방식
- Knapsack 알고리즘을 사용하였음.

### 소스코드
- 메모리 : 41472KB
- 시간 : 36ms
```c++
#include <bits/stdc++.h>

using namespace std;

int N, K, W[101], V[101], dp[101][100001];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> W[i] >> V[i];

    for(int i=1; i<=N; i++) {
        for(int j=0; j<=K; j++) {
            if(j<W[i]) dp[i][j] = dp[i-1][j];
            else if(dp[i-1][j-W[i]]+V[i] > dp[i-1][j]) dp[i][j] = dp[i-1][j-W[i]]+V[i];
            else dp[i][j] = dp[i-1][j];
        }
    }

    int M = 0;
    for(int i=0; i<=K; i++) M = max(M,dp[N][i]);
    
    cout << M;
}
```
- `D[i][j]` : `i`번째 물건을 넣거나 안 넣는 것을 정했을 때, 무게 `j`이하를 채우는 가치합 중 최대값    
- `D[i-1][j]` : `i`번째 물건을 넣지 않는 상태
- `D[i-1][j-W[i]]+V[i]` : `i`번째 물건을 넣는 상태
