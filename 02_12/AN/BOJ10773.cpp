#include <bits/stdc++.h>
using namespace std;
int N, k;
vector<int> v;
int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> k;
        if(!k) v.pop_back();
        else v.push_back(k);
    }
    cout << accumulate(v.begin(), v.end(), 0);
}