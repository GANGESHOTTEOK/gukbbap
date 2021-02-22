#include <iostream>
#include <string>
#include <stack>

using namespace std;

int n, t, maxNum;
stack <int> num;
string ans = "";

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    num.push(0);
    maxNum = 0;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (maxNum < t) {
            for (int j = maxNum + 1; j <= t; j++) {
                num.push(j);
                ans += "+\n";
            }
            num.pop();
            ans += "-\n";
            maxNum = t;
        }
        else {
            if (num.top() == t) {
                num.pop();
                ans += "-\n";
            }
            else {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << ans;
    return 0;
}


