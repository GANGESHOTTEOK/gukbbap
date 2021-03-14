#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define For(i,n) for(int i=0;i<n;i++)

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N,M,tmp;
    unordered_map<int,int> card;
    cin >> N;
    For(i,N){
        cin >> tmp;
        card[tmp]++;
    }
    cin >> M;
    For(i,M){
        cin >> tmp;
        cout << card[tmp] << ' ';
    }
}   