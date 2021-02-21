#include <iostream>
#include <string>
using namespace std;

bool video[64][64];
void find_quadtree(int x, int y, int size);

void quad_divider(int x, int y, int size){
    cout << '(';
    find_quadtree(x,y,size/2);
    find_quadtree(x+size/2,y,size/2);
    find_quadtree(x,y+size/2,size/2);
    find_quadtree(x+size/2,y+size/2,size/2);
    cout << ')';
}

int sqr_checker(int x, int y, int size){
    int sum = 0;
    for(int i=y;i<y+size;i++)
        for(int j=x;j<x+size;j++)
            sum += video[i][j];

    if(!sum) return 0;
    if(sum==size*size) return 1;
    return -1;
}

void find_quadtree(int x, int y, int size){
    if(!size) return;
    int tmp = sqr_checker(x,y,size);
    if(tmp<0) quad_divider(x,y,size);
    else cout << tmp;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N;
    string tmp;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> tmp;
        for(int j=0;j<N;j++) video[i][j] = tmp[j] - '0';
    }
    find_quadtree(0,0,N);
}

