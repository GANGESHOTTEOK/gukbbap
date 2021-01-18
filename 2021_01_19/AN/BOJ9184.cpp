#include <bits/stdc++.h>
using namespace std;
int m[21][21][21];
int w(int a, int b, int c) {
    if(a<=0 || b<=0 || c<=0) return 1;
    if(a>20 || b>20 || c>20) return w(20,20,20);
    if(m[a][b][c]) return m[a][b][c];
    if(a<b && b<c) return m[a][b][c] = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
    return m[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1, b, c-1) - w(a-1,b-1,c-1);
}
int main() {
    int x,y,z;
    while(1) {
        cin >> x >> y >> z;
        if(x==-1 && y==-1 && z==-1) break;
        cout << "w(" << x << ", " << y << ", " << z << ") = " << w(x,y,z) << "\n";
    }
}