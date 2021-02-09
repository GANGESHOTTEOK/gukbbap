#include <bits/stdc++.h>
using namespace std;
string a,b;
vector<int> s[1000], dp[1000];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> a >> b;
    for(int i=0; i<a.size(); i++) 
        for(int j=0; j<b.size(); j++) 
            if(a[i]==b[j]) s[j].push_back(i);

    for(int i=0; i<s[0].size(); i++) dp[0].push_back(1);

    for(int i=1; i<b.size(); i++) 
        for(int j=0; j<s[i].size(); j++) {
            int Max = 0;
            for(int k=0; k<i; k++) 
                for(int l=0; l<s[k].size(); l++) 
                    if(s[i][j] > s[k][l]) Max = max(dp[k][l], Max);
            dp[i].push_back(Max+1);
        }

    int Max = 0;
    for(int i=0; i<b.size(); i++) 
        for(int j=0; j<dp[i].size(); j++) 
            Max = max(dp[i][j], Max);
    
    cout << Max;
    
}