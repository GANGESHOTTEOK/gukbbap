#include <bits/stdc++.h>
using namespace std;
int N,m=0;
int main() {
    cin >> N;
    int n=N;
    while(n!=0) {
        n /= 10;
        m++;
    }
    int gen = 1000001;
    for(int k=N; k>=N-9*m; k--) {
        int sum=0, num=k;
        while(num!=0) {
            sum+=num%10;
            num/=10;
        }
        if(k+sum==N) gen=k;
    }
    if(gen==1000001) cout << 0;
    else cout << gen;
}