#include <iostream>
#include <algorithm>
using namespace std;

int n, c, result=0, arr[200000];

bool set_router(int distance){
    int neighborhood = arr[0], cnt=0;
    for(int i=1;i<n;i++)
        if(arr[i]-neighborhood >= distance) {
            cnt++;
            neighborhood = arr[i];
        }
    return cnt >= c-1;
}

void get_max_distance(){
    int left = 1, right = (arr[n-1]-arr[0])/(c-1), mid;
    while(left<=right){
        mid = (left+right)/2;
        if(set_router(mid)){
            result = max(result, mid);
            left = mid+1;
        }
        else right = mid-1;
    }
    return;
}

int main(){
    cin >> n >> c;
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr,arr+n);
    get_max_distance();
    cout << result;
}