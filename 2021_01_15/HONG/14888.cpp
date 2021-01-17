#include <iostream>
using namespace std;
#define MAXVALUE 1000000000

int N;
int maxval = -MAXVALUE, minval = MAXVALUE;
int AN[11],OPC[10],temp[11],OP[4] = {0,};
bool visited[11] = {false,};

int calculator(int *arr){
    int acc = AN[0];

    for(int i=0;i<N-1;i++){
        if(arr[i]==1) acc += AN[i+1];
        if(arr[i]==2) acc -= AN[i+1];
        if(arr[i]==3) acc *= AN[i+1];
        if(arr[i]==4) acc /= AN[i+1];
    }

    return acc;
}

void cbn(int idx){
    if (idx == N-1){
        int value  = calculator(temp);
        maxval = maxval > value ? maxval : value;
        minval = value > minval ? minval : value;
        return;
    }
    for (int i = 0; i < N-1; i++){
        if (!visited[i]){
            temp[idx] = OPC[i];
            visited[i] = true;
            cbn(idx + 1);
            visited[i] = false;
        }
    }
}

int main(){   
    cin >> N;

    for(int i=0;i<N;i++) cin >> AN[i];
    cin >> OP[0] >> OP[1] >> OP[2] >> OP[3];

    int idx = 0;

    for(int i=1;i<=4;i++)
        for(int j=0;j<OP[i-1];j++) 
            OPC[idx++] = i;

    cbn(0);
    
    cout << maxval << "\n" << minval;

    return 0;  
}