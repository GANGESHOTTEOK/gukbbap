#include <bits/stdc++.h>
using namespace std;
int N;
priority_queue<int, vector<int>, less<int>> q;
int main() {
    cin.tie(NULL);ios::sync_with_stdio(false);cout.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) {
        int x;
        cin >> x;
        if(x) q.push(x);
        else if(q.empty()) cout << "0" << "\n";
        else {
            cout << q.top() << "\n";
            q.pop();
        }
    }
}