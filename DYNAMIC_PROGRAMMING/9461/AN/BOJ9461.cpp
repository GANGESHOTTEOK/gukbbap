#include <bits/stdc++.h>
using namespace std;
long long m[101] = {0,1,1,1,};
long long fx(int n) {
    if(m[n]) return m[n];
    return m[n] = fx(n-3) + fx(n-2);
}
int main() {
    int T;
    cin >> T;
    int N[T];
    for(int i=0; i<T; i++) cin >> N[i];
    for(int i=0; i<T; i++) cout << fx(N[i]) << "\n";
    return 0;
}