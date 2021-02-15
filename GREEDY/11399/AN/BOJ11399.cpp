#include <bits/stdc++.h>
using namespace std;
int N, P[1001], sum=0;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) cin >> P[i];
    sort(P, P+N);
    for(int i=0; i<N; i++) sum += P[i]*(N-i);
    cout << sum;
}