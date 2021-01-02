#include <iostream>
#include <string>
using namespace std;

int main(){
    int N, M;
    int sum = 0;
    int min = 64;
    string test = "B";
    bool board[50][50];

    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin >> test;

        for(int j=0; j<M; j++){

            if((i%2 + j%2) % 2){
                if(test[j] == 'W') board[j][i] = true;
            }
            else if(test[j] == 'B') board[j][i] = true;
            else board[j][i] = false;
            
        }
    }

    for(int i=0; i<N-7; i++){
        
        for(int j=0; j<M-7; j++){
            
            sum = 0;

            for (int a=i; a<i+8; a++){
                for(int b=j; b<j+8; b++){
                    sum += board[a][j];
                }
            }
            cout << i << " " << j << " " << board[j][i] << endl;
            
            if( ((i%2 + j%2) % 2) == 0 && board[j][i] == true || ((i%2 + j%2) % 2) == 1 && board[j][i] == false ){
                cout << "1sum = " << 64-sum << endl;
                min = 64-sum<min ? sum : min;
            }
            else{
                cout << "2sum = " << sum << endl;
                min = sum<min ? sum : min; 
            }

       }
    }
    cout << "min = " << min << endl;

    return 0;
}
