#include <iostream>
#include<algorithm>
using namespace std;

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