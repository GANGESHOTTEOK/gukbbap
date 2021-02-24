#include <bits/stdc++.h>
using namespace std;
#define mod 1000
int N, ans[5][5], A[5][5];
long long B;
void multi(int (*x)[5], int (*y)[5]) {
    int ret[5][5] = {0,};
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) 
        for(int k=0; k<N; k++) ret[i][j] += (x[i][k]*y[k][j])%mod;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) x[i][j] = ret[i][j]%mod;
}
int main() {
    cin >> N >> B;
    for(int i=0; i<N; i++) 
        for(int j=0; j<N; j++) {
            cin >> A[i][j];
            ans[i][j]=A[i][j]%mod;
        }
    B--;
    while(B>0) {
        if(B%2) {multi(ans, A);}
        multi(A,A);
        B/=2;
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}