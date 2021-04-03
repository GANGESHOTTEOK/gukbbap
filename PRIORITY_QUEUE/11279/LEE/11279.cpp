#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, t;
    cin >> N;
    priority_queue<int, vector<int>, less<int>> pq;
    for (int i = 0; i < N; i++) {
        cin >> t;
        if (t == 0) {
            if (pq.size() == 0) cout << "0\n";
            else  {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else pq.push(t);
    }
    return 0;
}




