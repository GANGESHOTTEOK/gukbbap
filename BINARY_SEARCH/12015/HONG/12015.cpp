#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[1000001], lis[1000001];

int main(){ 
    cin >> N;
    for(int i=0;i<N;i++) cin >> arr[i];
    
    int idx=0;

    for(int i=0;i<N;i++)
        if(arr[i]>lis[idx]) lis[++idx] = arr[i];
        else {
            int* iter = lower_bound(lis, lis+idx, arr[i]);
            *iter = arr[i];
        } 

    cout << idx;
}
