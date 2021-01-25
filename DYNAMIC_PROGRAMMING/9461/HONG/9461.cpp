#include <iostream>
using namespace std;

int main(){
    int T,tmp;
    long int P[100]={1,1,1,2,2};
    cin >> T;

    for(int i=5;i<100;i++)
        P[i] = P[i-1] + P[i-5];
    
    for(int i=0;i<T;i++){
        cin >> tmp;
        cout << P[tmp-1] << "\n";
    }

    return 0;
}