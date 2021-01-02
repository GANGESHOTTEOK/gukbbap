#include <iostream>
using namespace std;

 int main(){
    int N, rank = 0;
    int A[50][2] = {0,};

    cin >> N;

    for (int x=0;x<N;x++) cin >> A[x][0] >> A[x][1];

    for(int i=0;i<N;i++){
        rank = 1;
    
        for(int j=0;j<N;j++){
            if(i==j) continue;
            if(A[i][0] < A[j][0] && A[i][1] < A[j][1])
                rank++;
        }
        
        cout << rank << endl;
    }
    return 0;
}