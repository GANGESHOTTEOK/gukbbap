#include <bits/stdc++.h>
using namespace std;
int N, K, A[10], sum=0, cnt=0;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N >> K;
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=N-1; i>-1; i--) {
        if(A[i]>K) continue;
        int n = K/A[i];
        cnt += n;
        K -= A[i]*n;
        if(!K) break;
    }
    cout << cnt;
}