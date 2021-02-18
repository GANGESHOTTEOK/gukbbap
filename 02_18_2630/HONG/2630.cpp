#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sqr[128][128];
int blue_sqr=0, white_sqr=0;

void find_square(int idx, int size){
    int sum = 0;
    for(int i=idx;i<idx+size;i++)
        for(int j=0;j<idx+size;j++)
            sum += sqr[i][j];
        
    if(sum && sum!=size*size) {
        if(sum) blue_sqr++;
        else white_sqr++;
    }
    
}

int main(){
    int N;
    cin >> N;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) cin >> sqr[i][j];


    return 0;
}