#include <iostream>
#include <stack>
using namespace std;

int main(){
    int N, tmp, arr[1000000];
    stack< pair<int, int> > stk;
    cin >> N;
    fill_n(arr,N,-1);
    for(int i=0;i<N;i++) {
        cin >> tmp;
        if(!i) stk.push({i, tmp});
        else
            while(!stk.empty() && stk.top().second < tmp){
                arr[stk.top().first] = tmp;
                stk.pop();
            }
        stk.push({i, tmp});
    }
    for(int i=0;i<N;i++) cout << arr[i] << " "; 
    return 0;
}


int main2(){
    int N, arr[1000000];
    stack<int> stk;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
        while(!stk.empty() && arr[stk.top()] < arr[i]){
            arr[stk.top()] = arr[i];
            stk.pop();
        }
        stk.push(i);
    }
    while(!stk.empty()) {
        arr[stk.top()] = -1;
        stk.pop();
    }
    for(int i=0;i<N;i++) cout << arr[i] << ' '; 
    return 0;
}