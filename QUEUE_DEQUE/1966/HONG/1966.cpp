#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
    vector<pair<int, int> > v;
    queue<int> q;
    int T, N, M, tmp;
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> N >> M;
        for(int i=0;i<N;i++) {
            cin >> tmp;
            v.push_back({i, tmp});
        }
        int max = 0;
        for(int i=0;i<N;i++){
            max = i;
            for(int j=i+1;j<N;j++)
                if(v[i].second < v[j].second) max = max(max, j);
            
            for(int j=i;j<=max;j++){
                
            }
            


        }
        
        
    }

    return 0;
}