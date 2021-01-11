#include <bits/stdc++.h>
using namespace std;
int N,M;
stack<int> s;
int chk[9]={0,};
void printStack(stack<int> sck) {
    vector<int> v;
    while(!sck.empty()) {
        v.push_back(sck.top());
        sck.pop();
    }
    for(int i=M-1; i>=0; i--) cout << v[i] << " ";
    cout << "\n";
}
void dfs(int depth) {
    if(depth==M) printStack(s);
    else {
        for(int i=1; i<=N; i++) {
            if(chk[i]==1) continue;
            chk[i] = 1;
            s.push(i);
            dfs(depth+1);
            s.pop();
            chk[i] = 0;
        }
    }
}
int main() {
    cin >> N >> M;
    dfs(0);
}