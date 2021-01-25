#include <bits/stdc++.h>
using namespace std;
int N, dp[1000][3]= {0, };
vector<int> weight[1000];
int fx(int n, int color) {
    if(n==0) return weight[0][color];
    if(dp[n][color]) return dp[n][color];
    int minWeight;
    if(color==0) minWeight = min(fx(n-1, 1), fx(n-1, 2));
    else if(color==1) minWeight = min(fx(n-1, 0), fx(n-1, 2));
    else if(color==2) minWeight = min(fx(n-1, 1), fx(n-1, 0));
    return dp[n][color] = minWeight + weight[n][color];
}
int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        int r,g,b;
        cin >> r >> g >> b;
        weight[i].push_back(r);
        weight[i].push_back(g);
        weight[i].push_back(b);
    }
    for(int i=0; i<3; i++) dp[0][i] = weight[0][i];
    for(int i=0; i<3; i++) fx(N-1, i);
    cout << *min_element(dp[N-1], dp[N-1]+3);
}