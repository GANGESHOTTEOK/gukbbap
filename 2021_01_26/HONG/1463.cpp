#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int dp[1000001] = {0,0,1,1};
    int N, min_dp = 0;

    cin >> N;

    for(int i=4;i<=N;i++){
        min_dp = 1000000;
        if(i%3==0) min_dp = dp[i/3] + 1;
        if(i%2==0) min_dp = min(min_dp, dp[i/2]+1);
        dp[i] = min(min_dp, dp[i-1]+1);
    }

    cout << dp[N];

    return 0;
}
