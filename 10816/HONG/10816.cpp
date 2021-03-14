#include <iostream>
#include <algorithm>
using namespace std;
#define For(i,n) for(int i=0;i<n;i++)

int N,card[500000];

int lwbd(int target){
    int start=0, end=N-1, mid;
    while(start<end){
        mid = (start+end)/2;
        if(card[mid]>=target) end = mid;
        else start = mid+1;
    }
    return end;
}

int upbd(int target){
    int start=0, end=N-1, mid;
    while(start<end){
        mid = (start+end)/2;
        if(card[mid]>target) end = mid;
        else start = mid+1;
    }
    return end;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int M, tmp;
    cin >> N;
    For(i,N) cin >> card[i];
    sort(card,card+N);
    cin >> M;
    For(i,M){
        cin >> tmp;
        int upper = upbd(tmp), lower = lwbd(tmp);
        if(upper==N-1 && card[N-1]==tmp) upper++;
        cout << upper - lower << ' ';
    }
}   