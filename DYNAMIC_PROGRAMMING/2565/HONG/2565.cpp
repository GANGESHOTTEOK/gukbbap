#include <iostream>
#include <algorithm>
using namespace std;

int N;
int poll[501] = {0,};
int dp[501] = {0,};

int main(){
    
    int tmp,ret = 0,Max = 0;

    cin >> N;

    for(int i=0;i<N;i++) {
        cin >> tmp;
        cin >> poll[tmp];
        ret = max(ret, tmp);
    }

    for(int i=0;i<ret;i++) {
        if(!poll[i+1]) continue;
        dp[i+1] = 1;
    }

    for(int i=1;i<=ret;i++){
        if(!poll[i]) continue;

        for(int j=1;j<i;j++){
            if(!poll[j]) continue;

            if (poll[i] > poll[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    cout << N - *max_element(dp,dp+501);
    

    return 0;
}