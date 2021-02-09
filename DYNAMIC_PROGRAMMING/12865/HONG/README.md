BOJ 12865번 평범한 배낭

<img src="https://i.ibb.co/LtcLncT/image.png" alt="image" border="0">

문제 접근
---

문제 풀이
---
- TOP-DOWN

```cpp
int N, K;
int value[101],weight[101], dp[100][100001] = {0,};

int knapsack(int n,int k){
    if(n < 0) return 0;
    if(dp[n][k]) return dp[n][k];
    if(k < weight[n]) return dp[n][k] = knapsack(n-1,k);

    return dp[n][k] = max(knapsack(n-1,k), knapsack(n-1,k-weight[n]) + value[n]) ;
}

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) cin >> weight[i] >> value[i];

    cout << knapsack(N-1,K);
    return 0;
}
```

- BOTTOM-UP

```cpp
int N, K;
int value[101],weight[101], dp[101][100001] = {0,};

int main(){
    cin >> N >> K;
    for(int i=1;i<=N;i++) cin >> weight[i] >> value[i];

    for(int i=1;i<=N;i++){
        for(int j=1;j<=K;j++){
            if(j < weight[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
        }
    }
    cout << dp[N][K];
    return 0;
}
```

결과
---
- TOP-DOWN

<img src="https://i.ibb.co/Y7CxVz7/image.png" alt="image" border="0">

- BOTTOM-UP
  
<img src="https://i.ibb.co/qWY9HRw/image.png" alt="image" border="0">