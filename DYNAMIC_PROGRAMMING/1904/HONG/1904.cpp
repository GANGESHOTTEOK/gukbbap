#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    int bin[1000000] = {1,2};

    for(int i=0;i<N-2;i++)
        bin[i+2] = (bin[i+1] + bin[i])%15746;

    cout << bin[N-1];

    return 0;
}