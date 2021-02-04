#include <iostream>
#include<algorithm>
using namespace std;

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