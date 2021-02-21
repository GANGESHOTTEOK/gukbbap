#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(void) {
    deque<int> dq;
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        if (t == "push_front") {
            int k;
            cin >> k;
            dq.push_front(k);
        }
        else if (t == "push_back") {
            int k;
            cin >> k;
            dq.push_back(k);
        }
        else if (t == "pop_front") {
            if (dq.empty()) cout << "-1\n";
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if (t == "pop_back") {
            if (dq.empty()) cout << "-1\n";
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if (t == "size") {
            cout << dq.size() << "\n";
        }
        else if (t == "empty") {
            cout << dq.empty() << "\n";
        }
        else if (t == "front") {
            if (dq.empty()) cout << "-1\n";
            else {
                cout << dq.front() << "\n";
            }
        }
        else if (t == "back") {
            if (dq.empty()) cout << "-1\n";
            else {
                cout << dq.back() << "\n";
            }
        }
    }
        
    return 0;
}
