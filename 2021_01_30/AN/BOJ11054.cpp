#include <bits/stdc++.h>
using namespace std;
int N, A[1000], dp1[1000]={1,}, dp2[1000];
int fx(int n) {
    if(dp1[n]) return dp1[n];
    int M = 0;
    for(int i=n-1; i>=0; i--) {
        if(M<fx(i) && A[i]<A[n]) M = fx(i);
    }
    return dp1[n] = M+1;
}
int gx(int n) {
    if(dp2[n]) return dp2[n];
    int M = 0;
    for(int i=n+1; i<N; i++) {
        if(M<gx(i) && A[i]<A[n]) M = gx(i);
    }
    return dp2[n] = M+1;
}
int main() {
    cin >> N;
    dp2[N-1] = 1;
    for(int i=0; i<N; i++) cin >> A[i];
    fx(N-1);
    gx(0);
    for(int i=0; i<N; i++) dp1[i] += dp2[i];
    cout << *max_element(dp1, dp1+N)-1;
}