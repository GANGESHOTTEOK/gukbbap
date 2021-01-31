#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int wine[100001] = {0,};
    int dp[10001][3] = {0,};
    int N;
    cin >> N;
    for(int i=0;i<N;i++) cin >> wine[i+1];
    
    for(int i=1;i<=N;i++){
        dp[i][0] = max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
        dp[i][1] = dp[i-1][0] + wine[i];
        dp[i][2] = dp[i-1][1] + wine[i];
    }

    cout << max({dp[N][0],dp[N][1],dp[N][2]});
    return 0;
}
