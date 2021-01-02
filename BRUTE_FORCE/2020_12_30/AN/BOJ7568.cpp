#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    cin >> N;
    vector<int> x(N),y(N),ranking(N);
    for(int i=0; i<N; i++) {
        cin >> x[i] >> y[i];
    }
    for(int i=0; i<N-1; i++) {
        for(int j=i+1; j<N; j++) {
            if(x[i]>x[j] && y[i]>y[j]) ranking[j]+=1;
            else if(x[i]<x[j] && y[i]<y[j]) ranking[i]+=1;
        }
    }
    for(auto k:ranking) {
        cout << k+1 << " ";
    }
}