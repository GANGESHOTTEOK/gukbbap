#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool comp(pair<int,int> a,pair<int,int> b){
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

int main(){
    int N,tmpx,tmpy;

    cin >> N;

    vector<pair<int,int>> loc;

    for(int i=0;i<N;i++){
        cin >> tmpx >> tmpy;
        loc.push_back(make_pair(tmpx,tmpy));
    }

    sort(loc.begin(),loc.end(),comp);

    for(int i=0;i<N;i++)
        cout << loc[i].first << " " << loc[i].second << "\n";

    return 0;
}