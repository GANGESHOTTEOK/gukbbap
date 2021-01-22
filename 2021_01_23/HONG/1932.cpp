#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N,P[500][500] = {0,};
    cin >> N;

    for(int i=0;i<N;i++)
        for(int j=0;j<=i;j++)
            cin >> P[i][j];
     
    for(int i=1;i<N;i++)
        for(int j=0;j<=i;j++){
            if(j==0) P[i][0] += P[i-1][0];
            else if(j==i) P[i][i] += P[i-1][i-1];
            else P[i][j] += max(P[i-1][j-1], P[i-1][j]);
        }

    int max = 0;

    for(int i=0;i<N;i++)
        max = max > P[N-1][i] ? max : P[N-1][i];
    
    cout << max;

    return 0;
}