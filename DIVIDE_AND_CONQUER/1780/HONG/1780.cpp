#include <iostream>
using namespace std;

int N, cnt[3]={0,}, sqr[2200][2200];

bool is_sqr(int x, int y, int n){
    for(int i=y;i<y+n;i++)
        for(int j=x;j<x+n;j++)
            if(sqr[y][x] != sqr[i][j]) return 1;
    return 0;
}

void nona_tree(int x, int y, int n){
    if(n==0) return;
    if(is_sqr(x,y,n)){
        for(int i=y;i<y+n;i+=n/3)
        for(int j=x;j<x+n;j+=n/3)
            nona_tree(j,i,n/3);
    }
    else cnt[sqr[y][x]+1]++;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) cin >> sqr[i][j];
    nona_tree(0,0,N);
    for(int i=0;i<3;i++) cout << cnt[i] << "\n";
}