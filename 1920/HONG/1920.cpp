#include <iostream>
#include <algorithm>
using namespace std;

int N, A[100000];

bool bin_srch(int target){
    int start=0, end=N-1, mid;
    if(target>A[end] || target<A[start]) return false;
    while(start<=end){
        mid = (start+end)/2;
        if(A[mid]==target) return true;
        else if(A[mid]<target) start = mid+1;
        else end = mid-1;
    }
    return false;
}

int main(){
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int M,tmp;
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    sort(A,A+N);
    cin >> M;
    for(int i=0;i<M;i++) {
        cin >> tmp;
        cout << bin_srch(tmp) << '\n';
    }
    return 0;
}