#include <iostream>
using namespace std;

int main(){
    long long dp[100][10] = {0,};
    int N;
    cin >> N;
    for(int i=1;i<10;i++) dp[0][i]=1;
    
    for(int i=1;i<N;i++){
        for(int j=0;j<10;j++){
            long long value = 0;
            if(j==0) value = dp[i-1][1];
            else if(j==9) value = dp[i-1][8];
            else value = dp[i-1][j-1] + dp[i-1][j+1];
            dp[i][j] = value%1000000000;
        }
    }

    long long sum = 0;
    for(int i=0;i<10;i++) sum += dp[N-1][i];
    cout << sum%1000000000;

    return 0;
}