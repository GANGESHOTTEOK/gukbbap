#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N,P[1000][3] = {0,};
    cin >> N;
    
    for(int i=0;i<N;i++)
        cin >> P[i][0] >> P[i][1] >> P[i][2];
    
    for(int i=1;i<N;i++)
        for(int j=0;j<3;j++)
            P[i][j] += min(P[i-1][(j+1)%3], P[i-1][(j+2)%3]);

    cout << min(min(P[N-1][0], P[N-1][1]), P[N-1][2]) ;

    return 0;
}