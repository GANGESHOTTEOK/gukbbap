#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    vector<long long> len(N-1), cost(N);
    for(int i=0; i<N-1; i++) cin >> len[i];
    for(int i=0; i<N; i++) cin >> cost[i];
    long long curMinCost = cost[0];
    long long total = curMinCost*len[0];
    for(int i=1; i<N-1; i++) {
        curMinCost = min(curMinCost,cost[i]);
        total += curMinCost*len[i];
    }
    cout << total;
}