#include <iostream>
using namespace std;

int main(){
    int W[21][21][21] = {0,};

    for(int i=0;i<21;i++)
        for(int j=0;j<21;j++)
            for(int k=0;k<21;k++){
                if(i<=0 || j<=0 || k<=0) W[i][j][k] = 1;
                else if(i<j && j<k) W[i][j][k] = W[i][j][k-1] + W[i][j-1][k-1] - W[i][j-1][k];
                else W[i][j][k] = W[i-1][j][k] + W[i-1][j-1][k] + W[i-1][j][k-1] - W[i-1][j-1][k-1];
            }

    int result, inp[3];

    while(true){
        cin >> inp[0] >> inp[1] >> inp[2];
        if (inp[0] == -1 && inp[1] == -1 && inp[2] == -1) break;
        else if (inp[0]<=0 || inp[1]<=0 || inp[2]<=0) result = 1;
        else if(inp[0]>20 || inp[1]>20 || inp[2]>20) result = W[20][20][20];
        else result = W[inp[0]][inp[1]][inp[2]];

        cout << "w(" << inp[0] << ", " << inp[1] << ", " << inp[2] << ") = " << result << "\n";
    }

    return 0;
}