#include <bits/stdc++.h>
using namespace std;
int N, M, num;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    map<int,int> cnt;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        if(!cnt.count(temp)) cnt[temp] = 1;
        else cnt[temp]++;
    }
    cin >> M;
    for(int i=0; i<M; i++) {
        cin >> num;
        if(!cnt.count(num)) cout << "0 ";
        else cout << cnt[num] << " ";
    }
}