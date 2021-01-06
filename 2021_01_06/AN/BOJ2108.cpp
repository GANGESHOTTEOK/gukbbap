#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    double mean = accumulate(v.begin(), v.end(), 0)/(double)N;
    int median = v[N/2];
    int range = v[N-1]-v[0];
    int mode=v[0],max=0, same=1, cnt=1;
    for(int i=1; i<=N; i++) {
        if(v[i-1]==v[i] && i!=N) cnt++;
        else {
            if(cnt>max) {
                max = cnt;
                mode = v[i-1];
                same = 1;
            }
            else if(cnt==max) {
                if(same==2) {
                    cnt=1;
                    continue;
                }
                else if(same==1) {
                    same++;
                    mode = v[i-1];
                }
            }
            cnt=1;
        }
    }
    cout << round(mean) << "\n" << median << "\n" << mode << "\n" << range;
}