#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define FOR(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string str; cin >> str; int length = str.length();
    vector <char> alphaList(length);
    FOR(i, length) alphaList[i] = str[i];
    sort(alphaList.rbegin(), alphaList.rend());
    FOR(i, length) cout << alphaList[i];
    return 0;
}

