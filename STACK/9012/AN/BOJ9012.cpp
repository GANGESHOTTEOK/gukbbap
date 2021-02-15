#include <bits/stdc++.h>
using namespace std;
int T;
string sentence;
int isVPS(string s) {
    stack<int> ps;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='(') ps.push(1);
        else {
            if(ps.empty()) return 0;
            else ps.pop();
        }
    }
    if(ps.empty()) return 1;
    else return 0;
}
int main() {
    cin >> T;
    for(int i=0; i<T; i++) {
        cin >> sentence;
        if(!isVPS(sentence)) cout << "NO\n";
        else cout << "YES\n";
    }
}