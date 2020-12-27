#include <iostream>
using namespace std;

int main(){
    int N , M;
    int C[100];
    cin >> N >> M;

    for(int i=0; i<N; i++) cin >> C[i];

    int max = 0;

    for(int i=0; i<N-2; i++){
        for(int j=i+1; j<N-1; j++){
            for(int k=j+1; k<N; k++){
                if(M >= C[i]+C[j]+C[k] && max < C[i]+C[j]+C[k])
                    max = C[i]+C[j]+C[k];
            }
        }
    }   

    cout << max;

    return 0;
}