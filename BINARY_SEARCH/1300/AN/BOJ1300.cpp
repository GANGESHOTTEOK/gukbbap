#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,k;
    cin >> N >> k;
    int left=1, right=k, ans=0;
    while(left<=right) {
        int mid=(left+right)/2;
        int cnt=0;
        for(int i=1; i<=N; i++) cnt += min(mid/i,N);
        if(cnt<k) left = mid+1;
        else {
            right = mid-1;
            ans = mid;
        }
    }
    cout << ans;
}