#include <iostream>
#include <algorithm>
using namespace std;

long long N, M, result=0, arr[1000000];

long long cut_tree(long long H){
    long long sum=0;
    for(long long i=0;i<N;i++)
        if(arr[i]>H) sum+=arr[i]-H;
    return sum;
}

void searh_H(){
    long long left = 1, right = arr[N-1], mid = 0;
    while(left<=right){
        mid = (left+right)/2;
        long long tree_length = cut_tree(mid);
        if(tree_length >= M) {
            result = max(mid,result);
            left = mid+1;
        }
        else right = mid-1;
    }
    return;
}

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++) cin >> arr[i];
    sort(arr,arr+N);
    searh_H();
    cout << result;
    return 0;
}