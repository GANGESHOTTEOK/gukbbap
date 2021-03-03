#include <iostream>
using namespace std;

int A,B,C;

int fx(int n, int k){
    if(k==0) return 1;

    int temp = fx(n,k/2);
    int result = (1LL * temp * temp) % C;

    if(k%2) result = 1LL * result * n % C;

    return result;
}

int main(){
    cin >> A >> B >> C;
    cout << fx(A,B);
    return 0;
}