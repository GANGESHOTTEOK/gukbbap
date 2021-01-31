#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[1000], dp[2][1000] = {0,};
    int N, Max = 0;

    cin >> N;
    for(int i=0;i<N;i++) cin >> arr[i];

    for(int i=0;i<N;i++){
        if(!dp[0][i]) dp[0][i] = dp[1][N-i-1] = 1;
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j] && dp[0][i] < dp[0][j]+1) dp[0][i] = dp[0][j]+1;
            if(arr[N-i-1] > arr[N-j-1] && dp[1][N-i-1] < dp[1][N-j-1]+1) dp[1][N-i-1] = dp[1][N-j-1]+1;
        }   
    }
    for(int i=0;i<N;i++) Max = max(Max, dp[0][i] + dp[1][i]);
    cout << Max - 1;
    
    return 0;
}