#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, n) for (int i = 0; i < n; i++)
using namespace std;
bool compare(pair<int, int> &v1, pair<int, int> &v2) {
    if (v1.second == v2.second) return v1.first < v2.first;
    return v1.second < v2.second;
}
int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int num; cin >> num;
    vector <pair <int, int>> numList(num);
    FOR(i, num) cin >> numList[i].first >> numList[i].second;
    sort(numList.begin(), numList.end(), compare);
    FOR(i, num) cout << numList[i].first << " " << numList[i].second << "\n";
    
    return 0;
}

