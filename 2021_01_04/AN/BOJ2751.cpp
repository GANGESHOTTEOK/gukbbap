#include <bits/stdc++.h>
using namespace std;
priority_queue< int, vector<int>, greater<int> > pq;
int main() {
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        pq.push(temp); 
    }
    while(!pq.empty()) {
        cout << pq.top() << "\n";
        pq.pop();
    }
}