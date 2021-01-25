#include <bits/stdc++.h>
using namespace std;
int N, m[500][500];
vector<int> v[500];
int fx(int n, int k) {
    if(!n) return v[0][0];
    if(m[n][k]!=-1) return m[n][k];
    if(!k) return m[n][k] = v[n][k]+fx(n-1, 0);
    if(k==n) return m[n][k] = v[n][k]+fx(n-1,n-1);
    return m[n][k] = max(fx(n-1,k-1), fx(n-1, k)) + v[n][k];
}
int main() {
    cin >> N;
    for(int i=1; i<=N; i++) {
        for(int j=0; j<i; j++) {
            int temp;
            cin >> temp;
            v[i-1].push_back(temp);
        }
    }
    memset(m,-1,sizeof(m));
    for(int i=0; i<N; i++) fx(N-1, i);
    cout << *max_element(m[N-1], m[N-1]+N);
}