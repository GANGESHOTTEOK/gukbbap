#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N,M,sum;
    int min = 32;
    char temp;
    bool board[50][50];

    cin >> N >> M;

    for(int i=0;i<N;i++){

        for(int j=0;j<M;j++){

            cin >> temp;

            if(temp == 'B' && ((i%2)+(j%2))!=1) board[j][i] = true;
            else if(temp == 'W' && ((i%2)+(j%2))==1) board[j][i] = true;
            else board[j][i] = false;
        }  
        
    }
    
    for(int i=0;i<=N-8;i++){

        for(int j=0;j<=M-8;j++){

            sum = 0;

            for(int a=i;a<8;a++){

                for(int b=j;b<8;b++){

                    sum += board[a][b];

                }
            }

            if(sum <= 32 && sum < min) {
                min = sum;
            }
            else if(sum > 32 && min > 64-sum) {
                min = 64-sum;
            }

            
        }   
    }

    cout << min;
}