#include <bits/stdc++.h>
using namespace std;
int T, N, M;
queue<int> q;
vector<int> v;
int getPriority(int i) {
    for(int j=0; j<N; j++) {
        if(v[i] < v[j]) return 0;
    }
    return 1;
}
int qPrinter(){
    int k = 0;
    while(!q.empty()) {
        int x = q.front();
        if(!getPriority(x)) {
            q.pop();
            q.push(x);
        }
        else {
            k++;
            q.pop();
            v[x] = 0;
            if(x==M) return k;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> T;
    for(int i=0; i<T; i++) {
        cin >> N >> M;
        v.clear();
        while(!q.empty()) q.pop();
        for(int j=0; j<N; j++) {
            q.push(j);
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        cout << qPrinter() << "\n";
    }
}