#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector< pair<int, int> > v;
    for(int i=0; i<N; i++) {
        int x,y;
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(), v.end());
    for(auto k:v) cout << k.first << " " << k.second << "\n";
}