#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str[2];
int dp[1001][1001] = {0,};
int maxlen = 0;

// int lcs(int a,int b){
//     if(a >= 1000) return 0;
//     if(dp[a] != -1) return dp[a];
//     maxlen = 0;
//     for(int i=b+1;i<1000;i++){

//         if(str[0][a] == str[1][i]) {
//             maxlen = max(maxlen, lcs(a+1,i)+1);
            
//         }
//     }
//     dp[a] = maxlen; 
//     // if(dp[a]==-1) dp[a] = 0;
//     return maxlen;
// }

int main(){
    int is_same = 0;
    cin >> str[0] >> str[1];

    for(int i=1;i<=str[0].length();i++){
        is_same = 0;
        for(int j=1;j<=str[1].length();j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

            if(str[0][i] == str[1][j]){
                for(int k = j;k<=str[1].length();k++)
                    dp[i][k] = dp[i][j]+1;
                break;
            }
        }
    }

    for(int i=1;i<=str[0].length();i++){

            for(int j=1;j<=str[1].length();j++){
                
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

    cout << dp[str[0].length()][str[1].length()] << " ";
    return 0;
}