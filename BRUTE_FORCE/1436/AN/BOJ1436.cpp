#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    cin >> N;
    int a = 666;
    vector<int> v={6,6,6};
    int cnt = 1;
    while(cnt!=N) {
        a++;
        for(int i=v.size()-1; i>=0; i--) { // v++
            if(v[i]!=9) {
                v[i]++;
                break;
            }
            else v[i] = 0;
            if(!i) v.insert(v.begin(), 1);
        }
        int con=0;
        for(int i=0; i<v.size(); i++) { // check three 6
            if(v[i]==6) con++;
            else con=0;
            if(con==3) {
                cnt++;
                break;
            }
        }
    }
    cout << a;
}