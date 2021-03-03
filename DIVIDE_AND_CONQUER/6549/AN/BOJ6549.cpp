#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll valueMax=0;
ll init(vector<ll> &h, vector<ll> &t, int node, int start, int end) {
    if(start == end) return t[node] = h[start];
    int mid = (start+end)/2;
    return t[node] = min(init(h, t, node * 2, start, mid), init(h, t, node * 2 + 1, mid + 1, end));
}
ll queryMin(vector<ll> &t, int node, int start, int end, int left, int right){
    if (left > end || right < start) return INT_MAX;
    if (left <= start && end <= right) return t[node];
    int mid = (start + end) / 2;
    return min(queryMin(t, node * 2, start, mid, left, right), queryMin(t, node * 2 + 1, mid + 1, end, left, right));
}
ll findMax(vector<ll> &h, vector<ll> &t, int left, int right) {
    if (left > n-1 || right < 0) return 0;
    ll seg = queryMin(t,1,0,n-1,left,right);
}
int main() {
    while(1) {
        cin >> n;
        if(!n) break;
        int k = (int)ceil(log2(n));
        int tree_size = (1<<(1+k));
        vector<ll> Histogram(n), tree(tree_size);
        for(int i=0; i<n; i++) cin >> Histogram[i];
        init(Histogram, tree, 1, 0, n-1);
        for(auto e:tree) cout << e << " ";
        // cout << queryMin(tree, 1, 0, n-1, 2,3) << endl;
        // cout << findMax(Histogram, tree);
        // for(int i=0; i<n; i++) cout << Histogram[i] << " ";
        // cout << endl;
    }
}