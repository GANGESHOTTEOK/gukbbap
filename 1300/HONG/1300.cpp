#include <iostream>
#include <algorithm>
using namespace std;

int n, k, result;

int bigger_then(int m){
    int sum = 0;
    for(int i=1;i<=n;i++)
        sum += min(n, m/i); // ???
    return sum;
}

void find_arr_k(){
    int left = 1, right = k, mid;
    while(left<=right){
        mid = (left+right)/2;
        if(bigger_then(mid) < k) {
            left = mid + 1;
        }
        else {
            right = mid-1;
            result = mid;
        }
    }
    return;
}

int main(){
    cin >> n >> k;
    find_arr_k();
    cout << result;
}


// 도와줘도와줘도와줘도와줘도와줘도와줘도와줘도와줘도와줘도와줘