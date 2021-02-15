
# 백준 4949번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 2월 15일

---

### 접근 방식
- 

### 소스코드
- 메모리 : 2020KB
- 시간 : 4ms
```c++
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
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    while(1) {
        getline(cin, sentence);
        if(sentence==".") break;
        if(!isVPS(sentence)) cout << "no\n";
        else cout << "yes\n";
    }
}
```