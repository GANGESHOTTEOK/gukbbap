#include <bits/stdc++.h>
using namespace std;
int zeroCnt, oneCnt;
vector< pair<int,int> > memoCnt(41);
vector<int> m(41);
int fibo(int n) {
    if(!n) {
        zeroCnt++;
        return 0;
    }
    else if(n==1) {
        oneCnt++;
        return 1;
    }
    else if(m[n]) {
        zeroCnt += memoCnt[n].first;
        oneCnt += memoCnt[n].second;
        return m[n];
    }
    else {
        m[n] = fibo(n-1) + fibo(n-2);
        memoCnt[n].first = zeroCnt;
        memoCnt[n].second = oneCnt;
        return m[n];
    }
}
int main() {
    int T, N;
    cin >> T;
    for(int i=0; i<T; i++) {
        cin >> N;
        zeroCnt = oneCnt = 0;
        fibo(N);
        cout << zeroCnt << " " << oneCnt << "\n";
    }
    return 0;
}