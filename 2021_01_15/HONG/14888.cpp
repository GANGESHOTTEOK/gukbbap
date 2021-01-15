#include <iostream>
using namespace std;

int main(){
    int N, idx = 0;
    int AN[11],OPC[10],OP[4] = {0,};   

    cin >> N;

    for(int i=0;i<N;i++) cin >> AN[i];

    cin >> OP[0] >> OP[1] >> OP[3] >> OP[4];

    for(int i=1;i<=4;i++)
        for(int j=0;j<OP[i];j++) 
            OPC[idx++] = i;


    
    return 0;  
}

void combination(int idx){
    if (idx >= 4){
        for (int i = 0; i < 4; i++){
            cout << result[i] << " ";
        }
        cout << endl;
        combination_count++;
        return;
    }
    for (int i = 0; i < N; i++){
        if (!visited[i]){
            result[idx] = arr[i];
            visited[i] = true;
            combination(idx + 1);
            visited[i] = false;
        }
    }
}

