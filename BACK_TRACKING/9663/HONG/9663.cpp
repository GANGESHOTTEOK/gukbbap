#include <iostream>
using namespace std;
#define MAX 15

bool board[MAX][MAX];
int big,small,N;
int count = 0;

bool find_N_queen(int i){

    for(int j=0;j<N;j++){

        if(board[j]) continue;
        if(i == N) return true;

        if(j>i) { big=j; small=i; }
        else { big=i; small=j; }

        for(int k=N-1;k>small;k--) board[k][k-(big-small)] = true;
        for(int k=small+1;k<=2*big-small;k++) board[2*big-small-k][k] = true;
        for(int k=i;k<N;k++) board[j][k]=true;
        
        find_N_queen(i+1);
    }
    return false;
}

void board_clear(){
    for(int i=0;i<MAX;i++) 
        for(int j=0;i<MAX;j++)
            board[i][j] = false;
}

int main(){
    // 1열당 1퀸 ,  1행당 1퀸 , 즉 같은 열이나 같은 행에서는 2개이상의 퀸이 나오지않는다
    // 1행을 기준으로 for 문을 돌리면 2행부터 1행에 위치하는 퀸의 열에 중복되지 않도록 배치
    // 전 퀸의 대각선도 고려한다.   

    cin >> N;

    for(int i=0;i<N;i++)
        if(find_N_queen())

    return 0;
}