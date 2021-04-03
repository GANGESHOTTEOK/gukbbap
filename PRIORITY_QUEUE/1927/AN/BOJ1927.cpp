#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL);ios::sync_with_stdio(false);cout.tie(NULL);
    int N;
    cin >> N;
    priority_queue< int,vector<int>, greater<int> > pq;
    for(int i=0; i<N; i++) {
        int x;
        cin >> x;
        if(x) pq.push(x);
        else {
            if(pq.empty()) {
                cout << "0\n";
                continue;
            }
            cout << pq.top() << "\n";
            pq.pop();
        }
    }
}