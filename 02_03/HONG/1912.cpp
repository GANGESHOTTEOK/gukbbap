#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int N;
    int arr[100000],dp[100000];

    cin >> N;

    for(int i=0;i<N;i++) cin >> arr[i];

    dp[0] = arr[0];

    for(int i=1;i<N;i++){
        if(dp[i-1] < 0) dp[i] = arr[i];
        else dp[i] = dp[i-1] + arr[i];
    }

    cout << *max_element(dp,dp+N);

    return 0;
}