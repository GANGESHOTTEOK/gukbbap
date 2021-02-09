#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
pair<int, int> P;
vector<pair<int, int>> arr;
 
bool comp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}
 
int main(){
    int N;
    cin >> N;
    
    int start, end;
    for(int i = 0; i < N; i++){
        cin >> start >> end;
        arr.push_back(make_pair(start, end));
    }
    sort(arr.begin(), arr.end(), comp);
    
    int now = arr[0].second;
    int cnt = 1;
    for(int i = 1; i < N; i++){
        if(now <= arr[i].first){
            cnt++;
            now = arr[i].second;
        }
    }
    
    cout << cnt << '\n';
    
    return 0;
}