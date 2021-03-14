#include <iostream>
#include <algorithm>
using namespace std;
#define For(i,n) for(int i=0;i<n;i++)

long long N,K,high,low=1,mid,line[10000];

int line_cutter(int len){
    int sum=0;
    For(i,K) sum+=line[i]/len;
    return sum;
}

int main(){
    cin >> K >> N;
    For(i,K) cin >> line[i];
    high = *max_element(line,line+K);
    while(low<high){
        mid = (low+high)/2;
        if(line_cutter(mid)<N) high = mid;
        else low = mid+1;
    }
    if(high == *max_element(line,line+K)) high++;
    cout << high-1;
}