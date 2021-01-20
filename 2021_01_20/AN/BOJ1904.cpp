#include <iostream>
using namespace std;
long long reg[1000001];
long long fx(int n) {
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 2;
    if(reg[n]) return reg[n]%15746;
    return (reg[n] = fx(n-1) + fx(n-2))%15746;
};
int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);
    int N;
    cin >> N;
    cout << fx(N);
    return 0;
}