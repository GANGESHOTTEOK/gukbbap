#include <iostream>
using namespace std;

int main(){
    int arr[1000], dp[1000] = {0,};
    int N, Max = 0;

    cin >> N;
    for(int i=0;i<N;i++) cin >> arr[i];

    for(int i=0;i<N;i++){
        if(!dp[i]) dp[i]++;
        for(int j=0;j<i;j++)
            if(arr[i] > arr[j] && dp[i] < dp[j]+1) dp[i] = dp[j]+1;
        Max = Max > dp[i] ? Max : dp[i];
    }
    cout << Max;
    
    return 0;
}