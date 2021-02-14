#include <bits/stdc++.h>
using namespace std;
int N, k;
stack<int> s;
int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        string cmd;
        cin >> cmd;
        if(!cmd.compare("push")) {
            cin >> k;
            s.push(k);
        }
        else if(!cmd.compare("size")) cout << s.size() << "\n";
        else if(!cmd.compare("empty")) cout << s.empty() << "\n";
        else {
            if(s.empty()) cout << "-1\n";
            else {
                cout << s.top() << "\n";
                if(!cmd.compare("pop")) s.pop();
            }
        }
    }
}