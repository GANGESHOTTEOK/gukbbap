#include <bits/stdc++.h>
using namespace std;
int n;
stack<int> s;
vector<char> v;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    int k=0;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        if(k<a) {
            while(k<a) {
                v.push_back('+');
                s.push(++k);
            }
        }
        if(a==s.top()) {
            v.push_back('-');
            s.pop();
        }
        else {
            cout << "NO\n";
            return 0;
        }
    }
    for(auto k:v) cout << k << "\n";
}