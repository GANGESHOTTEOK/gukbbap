#include <bits/stdc++.h>
using namespace std;
int N,M;
vector<int> c;
int main() {
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        if(temp<M) c.push_back(temp);
    }
    int max=0;
    for(int i=0; i<c.size(); i++) {
        for(int j=i+1; j<c.size(); j++) {
            for(int k=j+1; k<c.size(); k++) {
                int sum = c[i]+c[j]+c[k];
                if(sum<=M && max<sum) max=sum;
            }
        }
    }
    cout << max;
}