#include <bits/stdc++.h>
using namespace std;
int cmp(pair<int,int> &a, pair<int,int> &b) {
    if(a.second==b.second) return a.first < b.first;
    return a.second < b.second;
}
int main() {
    int N;
    cin >> N;
    vector< pair<int ,int> > v;
    for(int i=0; i<N; i++) {
        int x,y;
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(), v.end(), cmp);
    for(auto k:v) cout << k.first << " " << k.second << "\n";
}