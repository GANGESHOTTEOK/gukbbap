#include <bits/stdc++.h>
using namespace std;
int N, paper[2200][2200], cnt[3];
int isPaper(int row, int col, int n) {
    int kind = paper[row][col];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) 
        if(kind != paper[row+i][col+j]) return -2;
    return kind;
}
void cutPaper(int row, int col, int n) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            int r = row+i*n/3;
            int c = col+j*n/3;
            int result = isPaper(r,c,n/3);
            if(result == -2) cutPaper(r,c,n/3);
            else cnt[result+1]++;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin >> paper[i][j];
    if(isPaper(0,0,N) != -2) cnt[paper[0][0]+1]++;
    else cutPaper(0,0,N);
    for(auto k:cnt) cout << k << "\n";
}