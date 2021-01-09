#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    vector<int> v;
    cin >> N;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for(auto k:v) cout << k << "\n";
}