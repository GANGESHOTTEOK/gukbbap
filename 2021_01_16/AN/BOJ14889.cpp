#include <bits/stdc++.h>
using namespace std;
int N;
int S[20][20], chk[20];
vector<int> start, diff;
int getDiff() {
    int s=0, l=0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(i==j) continue;
            if(!chk[i] && !chk[j]) s += S[i][j];
            else if(chk[i]==1 && chk[j]==1) l+= S[i][j];
        }
    }
    return abs(s-l);
}
void dfs(int depth) {
    if(depth==N/2) {
        diff.push_back(getDiff());
        return;
    }
    for(int i=start.back()+1; i<N; i++) {
        if(chk[i]!=0) continue;
        chk[i]=1;
        start.push_back(i);
        dfs(depth+1);
        start.pop_back();
        chk[i]=0;
    }
}
int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) 
            cin >> S[i][j];
    }
    start.push_back(0);
    chk[0] = 1;
    dfs(1);
    cout << *min_element(diff.begin(), diff.end());
}