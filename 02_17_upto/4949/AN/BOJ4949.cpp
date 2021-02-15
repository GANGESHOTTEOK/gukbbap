#include <bits/stdc++.h>
using namespace std;
int T;
string sentence;
int isVPS(string s) {
    stack<int> ps;
    for(int i=0; i<s.size(); i++) {
        if(s[i]!='(' && s[i]!='[' && s[i]!=']' && s[i]!=')') continue;
        if(s[i]=='(') ps.push(1);
        else if(s[i]=='[') ps.push(0);
        else {
            if(ps.empty()) return 0;
            else if(s[i]==')') {
                if(!ps.top()) return 0;
                else ps.pop();
            }
            else if(s[i]==']') {
                if(ps.top()) return 0;
                else ps.pop();
            }
        }
    }
    if(ps.empty()) return 1;
    else return 0;
}
int main() {
    while(1) {
        getline(cin, sentence);
        if(sentence==".") break;
        if(!isVPS(sentence)) cout << "no\n";
        else cout << "yes\n";
    }
}