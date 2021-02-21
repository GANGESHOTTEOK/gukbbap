#include <iostream>
#include <deque>

using namespace std;

int main(void) {
    deque<int> dq;
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }
    
    int m;
    cin >> m;
    deque<int> target;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        target.push_back(t);
    }
    
    int ans = 0;
    while(!target.empty()) {
        if (dq[0] == target[0]) {
            target.pop_front();
            dq.pop_front();
        }
        else {
            int i;
            for (i = 0; dq[i] != target[0]; i++) ;
            if (i > dq.size() / 2) {
                while (dq[0] != target[0]) {
                    dq.push_front(dq.back());
                    dq.pop_back();
                    ans++;
                }
            }
            else {
                while (dq[0] != target[0]) {
                    dq.push_back(dq.front());
                    dq.pop_front();
                    ans++;
                }
            }
            dq.pop_front();
            target.pop_front();
        }
    }
    cout << ans;
    return 0;
}
