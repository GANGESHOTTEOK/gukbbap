#include <iostream>
using namespace std;

int main(){
    int N,K,sum=0;
    int A[10];
    cin >> N >> K;
    for(int i=0;i<N;i++) cin >> A[i];

    for(int i=N-1;i>=0;i--){
        sum += K / A[i];
        K %= A[i];
    }

    cout << sum;
    return 0;
}