#include <iostream>
using namespace std;
#define MAX 15

bool board[MAX][MAX];
bool x_big;
int big,small;

int find_N_queen(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[j]) continue;

            x_big = j>i ? true : false;
            big = x_big ? j : i;
            small = x_big ? i : j;

            if(x_big){
                for(int a=0;a<n-(big-small);a++) board[big-small+a][a] = true;
                for(int b=0;b<=j+big-small;b++) board[j+big-small-b][b] = true;
            }
            else {
                for(int a=0;a<n-(big-small);a++) board[a][big-small+a] = true;
                for(int b=0;b<=i+big-small;b++) board[b][i+big-small-b] = true;
            }
            for(int y=0;y<n;y++) board[j][y]=true;
            
        }
    }
}

int main(){
    // 1열당 1퀸 ,  1행당 1퀸 , 즉 같은 열이나 같은 행에서는 2개이상의 퀸이 나오지않는다
    // 1행을 기준으로 for 문을 돌리면 2행부터 1행에 위치하는 퀸의 열에 중복되지 않도록 배치
    // 전 퀸의 대각선도 고려한다.   

    int N;

    cin >> N;

    for(int i=0;i<MAX;i++) b
        for(int j=0;i<MAX;j++)
            board[i][j] = false;
    

    find_N_queen(N);


    return 0;
}