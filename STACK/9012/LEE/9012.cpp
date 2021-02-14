#include <iostream>
#include <stack>

using namespace std;

int n;

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        stack <char> s;
        char string[50]; cin >> string;
        for (char *c = string; *c; c++) {
            if (*c == '(') s.push(*c);
            else {
                if (s.size() == 0) s.push(*c);
                else if (s.top() == '(')s.pop();
            }
        }
        if (s.size() != 0) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
