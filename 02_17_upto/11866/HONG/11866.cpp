#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    queue<int> q;
    vector<int> v;
    int N, K, arr[1000];
    cin >> N >> K;
    for(int i=0;i<N;i++) q.push(i+1);
    for(int i=1;!q.empty();i++){
        if(i%K) q.push(q.front());
        else v.push_back(q.front());
        q.pop();
    }
    cout << '<';
    for(int i=0;i<N-1;i++) cout << v[i] << ", ";
    cout << v[N-1] << '>';
    return 0;
}
