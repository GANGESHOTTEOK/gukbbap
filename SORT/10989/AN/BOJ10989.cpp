#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int a[10001]={0,};
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        a[temp]++;
    }
    for(int i=0; i<10001; i++) {
        for(int j=0; j<a[i]; j++) {
            cout << i << "\n";
        }
    }
}