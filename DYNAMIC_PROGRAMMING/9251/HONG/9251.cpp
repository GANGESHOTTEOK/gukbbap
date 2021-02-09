#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main(){
    string str[2];
    int dp[1001][1001] = {0,};
    
    cin >> str[0] >> str[1];

    for(int i=1;i<=str[0].length();i++)
        for(int j=1;j<=str[1].length();j++){
            if(str[0][i-1] == str[1][j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }

    cout << dp[str[0].length()][str[1].length()];
    return 0;
}