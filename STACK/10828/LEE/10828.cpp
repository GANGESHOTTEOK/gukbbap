#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
string s;
int d;
vector <int> stack;

int main(void) {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s.compare("push") == 0) {
            cin >> d;
            stack.push_back(d);
        }
        else if (s.compare("pop") == 0) {
            if (stack.size()) {
                cout << stack.back() << endl;
                stack.pop_back();
            }
            else cout << -1 << endl;
        }
        else if (s.compare("size") == 0) {
            cout << stack.size() << endl;
        }
        else if (s.compare("empty") == 0) {
            cout << int(stack.size() == 0) << endl;
        }
        else {
            if (stack.size()) cout << stack.back() << endl;
            else cout << -1 << endl;
        }
    }
    return 0;
}
