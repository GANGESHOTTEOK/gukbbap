#include <bits/stdc++.h>
using namespace std;

int N, a[128][128], blue=0, white=0;
int idx[4][2] = {{0,0}, {0,1}, {1,0}, {1,1}};

int isPaper(int row, int col, int n) {
    int color = a[row][col];
    for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++)  // a[row][col]과 다른 색이면 -1을 반환
            if(a[row+i][col+j] != color) return -1; 
    return color;
}

void cutPaper(int row, int col, int n) {
    if(!n) return;
    for(int i=0; i<4; i++) {
        int r = row + n/2*idx[i][0];
        int c = col + n/2*idx[i][1];
        
        int result = isPaper(r,c,n/2);

        if(result == -1) cutPaper(r,c,n/2);
        else if(!result) white++;
        else blue++;
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin >> a[i][j];
    cutPaper(0,0,N);
    cout << white << "\n" << blue;
}