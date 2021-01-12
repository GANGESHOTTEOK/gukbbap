#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FOR(i, n) for (int i = 0; i < n; i++)
using namespace std;

bool compare(string & str1, string & str2) {
    if (str1.length() == str2.length()) return str1.compare(str2) < 0;
    return str1.length() < str2.length();
}

bool checkDuplicate(vector <string> & strList, string & str) {
    FOR(i, strList.size())
        if (!str.compare(strList[i])) return true;
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int num; cin >> num;
    vector <string> strList;
    FOR(i, num) {
        string temp; cin >> temp;
        if (!checkDuplicate(strList, temp)) strList.push_back(temp);
    }
    sort(strList.begin(), strList.end(), compare);
    FOR(i, strList.size()) cout << strList[i] << "\n";
    return 0;
}

