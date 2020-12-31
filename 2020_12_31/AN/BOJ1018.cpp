#include <bits/stdc++.h>
using namespace std;
int N, M, Min=100;
vector<string> board;
int getCount(int row, int col) {
    int black=0, white=0;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            char b = board[row+i][col+j];
            if((!(i%2) && !(j%2)) || ((i%2) && (j%2))) {
                if(b=='W') black++;
                else white++;
            }
            else {
                if(b=='W') white++;
                else black++;
            }
        }
    }
    if(black<white) return black;
    else return white;
}
int main() {
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        string temp;
        cin >> temp;
        board.push_back(temp);
    }
    for(int i=0; i<N-7; i++) {
        for(int j=0; j<M-7; j++) {
            int cnt = getCount(i,j);
            if(cnt<Min) Min = cnt;
        }
    }
    cout << Min;
}