#include <iostream>
using namespace std;

int main(){
    int N, M, K;
    int a[100][100], b[100][100];
    cin >> N >> M;
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) cin >> a[i][j];
    cin >> M >> K;
    for(int i=0;i<M;i++) for(int j=0;j<K;j++) cin >> b[i][j];
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<K;j++) {
            int sum = 0;
            for(int k=0;k<M;k++) sum += a[i][k] * b[k][j];
            cout << sum << " ";
        }
        cout << "\n";
    }   
    return 0;
}