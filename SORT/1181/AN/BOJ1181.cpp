#include <bits/stdc++.h>
using namespace std;
int cmp(pair<int, string> &a, pair<int, string> &b) {
    if(a.first == b.first) {
        if (a.second.compare(b.second)>=0) return 0;
        else return 1;
    }
    return a.first < b.first;
}
int main() {
    int N;
    cin >> N;
    vector< pair<int, string> > v;
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        v.push_back(make_pair(s.length(),s));
    }
    sort(v.begin(), v.end(), cmp);
    cout << v[0].second << "\n";
    for(int i=1; i<N; i++) {
        if(!v[i].second.compare(v[i-1].second)) continue;
        else cout << v[i].second << "\n";
    }
}