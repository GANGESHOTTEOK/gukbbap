
# 백준 1149번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 1월 22일 15시 29분

---

### 접근 방식
- 동적계획법 사용.

### 소스코드
- 메모리 : 2052KB
- 시간 : 0ms
```c++
#include <bits/stdc++.h>

using namespace std;

int N, dp[1000][3]= {0, };
vector<int> weight[1000];

int fx(int n, int color) {
    if(n==0) return weight[0][color];
    if(dp[n][color]) return dp[n][color];

    int minWeight;
    if(color==0) minWeight = min(fx(n-1, 1), fx(n-1, 2));
    else if(color==1) minWeight = min(fx(n-1, 0), fx(n-1, 2));
    else if(color==2) minWeight = min(fx(n-1, 1), fx(n-1, 0));
    
    return dp[n][color] = minWeight + weight[n][color];
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        int r,g,b;
        cin >> r >> g >> b;
        weight[i].push_back(r);
        weight[i].push_back(g);
        weight[i].push_back(b);
    }
    for(int i=0; i<3; i++) dp[0][i] = weight[0][i];

    for(int i=0; i<3; i++) fx(N-1, i);

    cout << *min_element(dp[N-1], dp[N-1]+3);
}
```
- `fx(int n, int color)` : `n`번째 집에 color를 칠할 경우의 최저 비용을 반환하는 함수이다.
- `dp[1000][3]` : `fx(n,color)`의 결과를 `dp[n][color]`에 저장하는 이차원 배열