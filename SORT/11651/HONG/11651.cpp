#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
    int N,tmpx,tmpy;

    cin >> N;

    vector<pair<int,int>> loc;

    for(int i=0;i<N;i++){
        cin >> tmpx >> tmpy;
        loc.push_back(make_pair(tmpx,tmpy));
    }

    sort(loc.begin(),loc.end(),[](pair<int,int> a,pair<int,int> b){
        return a.second == b.second ? a.first < b.first : a.second < b.second;});

    for(auto i:loc)
        cout << i.first << " " << i.second << "\n";

    return 0;
}