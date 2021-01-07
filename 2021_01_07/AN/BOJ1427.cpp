#include <bits/stdc++.h>
using namespace std;
int cmp(int a, int b) {
    return a>b;
}
int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end(), cmp);
    cout << s;
}