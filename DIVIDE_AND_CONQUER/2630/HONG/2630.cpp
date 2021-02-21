#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sqr[128][128];
int blue_sqr=0, white_sqr=0;

void find_square(int x, int y, int size){
    if(size==1){
        if(sqr[y][x]) blue_sqr++;
        else white_sqr++;
        return;
    }
    int sum = 0;
    for(int i=y;i<y+size;i++)
        for(int j=x;j<x+size;j++)
            sum += sqr[i][j];

    if(!sum || sum==size*size) {
        if(sum) blue_sqr++;
        else white_sqr++;
        return;
    }
    else {
        find_square(x,y,size/2);
        find_square(x+size/2,y,size/2);
        find_square(x,y+size/2,size/2);
        find_square(x+size/2,y+size/2,size/2);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N;
    cin >> N;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) cin >> sqr[i][j];
    find_square(0,0,N);
    cout << white_sqr << "\n" << blue_sqr++;
}