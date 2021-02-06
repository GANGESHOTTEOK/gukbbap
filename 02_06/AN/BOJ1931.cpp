#include <bits/stdc++.h>
using namespace std;
int N, cnt=0;
int cmp(pair<int,int> &a, pair<int,int> &b) {
    return a.second==b.second ? a.first<b.first : a.second<b.second;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    vector< pair<int,int> > A(N);
    for(int i=0; i<N; i++) cin >> A[i].first >> A[i].second;
    sort(A.begin(),A.end(),cmp);
    int K = A[0].first;
    for(int i=0; i<N; i++) {
        if(K>A[i].first) continue;
        cnt++;
        K = A[i].second;
    }
    cout << cnt;
}