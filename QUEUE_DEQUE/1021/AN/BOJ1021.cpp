#include <bits/stdc++.h>
using namespace std;
int N, M, x, cnt=0;
deque<int> dq;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M;
    for(int i=1; i<=N; i++) dq.push_back(i);
    for(int i=0; i<M; i++) {
        cin >> x;
        deque<int>::iterator iter = find(dq.begin(), dq.end(), x);
        int left = iter-dq.begin();
        if(left<=dq.size()/2) {
            for(int j=0; j<left; j++) {
                cnt++;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            for(int j=0; j<dq.size()-left; j++) {
                cnt++;
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        dq.pop_front();
    }
    cout << cnt;
}