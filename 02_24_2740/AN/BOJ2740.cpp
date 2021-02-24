#include <bits/stdc++.h>
using namespace std;
int N,M,K;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M;
    int A[N][M];
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) cin >> A[i][j];
    cin >> M >> K;
    int B[M][K];
    for(int i=0; i<M; i++) for(int j=0; j<K; j++) cin >> B[i][j];
    int ans[N][K];
    memset(ans,0,sizeof(ans));
    for(int i=0; i<N; i++) {
        for(int j=0; j<K; j++) {
            for(int k=0; k<M; k++) {
                ans[i][j] += A[i][k]*B[k][j];
            }
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}