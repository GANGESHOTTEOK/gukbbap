#include <bits/stdc++.h>
using namespace std;
int T, n, flag=1, dir=1;
string p, x;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> T;
    for(int i=0; i<T; i++) {
        cin >> p >> n >> x;
        deque<string> dq;
        string temp;
        for(int j=1; j<x.size()-1; j++) {
            if(x[j]==',') {
                dq.push_back(temp);
                temp = "";
                continue;
            }
            temp.append(x,j,1);
        }
        dq.push_back(temp);
        for(int j=0; j<p.size(); j++) {
            if(p[j]=='R') {
                if(!dir) dir=1;
                else dir=0;
            }
            else {
                if(dq.empty()) {
                    flag = 0;
                    break;
                }
                if(!n) flag = 0;
                if(!dir) dq.pop_back();
                else dq.pop_front();
            }
        }
        if(flag) {
            cout << "[";
            if(!dir) {
                for(auto k = dq.end()-1; k>dq.begin(); k--) cout << *k << ",";
                if(dq.size()) cout << dq.front();
            }
            else {
                for(auto k = dq.begin(); k<dq.end()-1; k++) cout << *k << ",";
                if(dq.size()) cout << dq.back();
            }
            cout << "]\n";
        }
        else cout << "error\n";
        flag = 1;
        dir = 1;
    }
}