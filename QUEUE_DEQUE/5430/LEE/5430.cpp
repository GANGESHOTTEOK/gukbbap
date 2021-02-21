#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        int c_index = 0;
        
        int q;
        cin >> q;
        
        int cnt_delete = 0;
        for (int j = 0; command[j]; j++) {
            if (command[j] == 'D') cnt_delete++;
        }
        
        string array;
        cin >> array;
        deque<int> dq;
        int temp = 0;
        for (int j = 1; array[j]; j++) {
            if (array[j] >= '0' && array[j] <= '9') {
                temp = temp * 10 + array[j] - '0';
            }
            else if (array[j - 1] >= '0' && array[j - 1] <= '9') {
                dq.push_back(temp);
                temp = 0;
            }
        }
        bool reverse = false;
        if (cnt_delete > q) cout << "error\n";
        else {
            for (int j = 0; command[j]; j++) {
                if (command[j] == 'R') {
                    reverse = !reverse;
                }
                else {
                    if (reverse) {
                        dq.pop_back();
                    }
                    else {
                        dq.pop_front();
                    }
                }
            }
            cout << "[";
            if (reverse) {
                deque<int>::reverse_iterator iter;
                for (iter = dq.rbegin(); iter != dq.rend(); iter++) {
                    cout << *iter;
                    if (iter < dq.rend() - 1) cout << ",";
                }
            }
            else {
                deque<int>::iterator iter;
                for (iter = dq.begin(); iter != dq.end(); iter++) {
                    cout << *iter;
                    if (iter < dq.end() - 1) cout << ",";
                }
            }
            cout << "]\n";
        }
    }

    
    
    return 0;
}
