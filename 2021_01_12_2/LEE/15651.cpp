#include <iostream>
#include <vector>

#define FOR(i, n) for (int i = 0; i < n; i++)
using namespace std;

void combination(vector <int> & numList, int n, int cnt) {
    if (numList.size() == cnt) {
        FOR(i, numList.size()) cout << numList[i] + 1 << " ";
        cout << "\n";
        return ;
    }
    
    FOR(i, n) {
        numList.push_back(i);
        combination(numList, n, cnt);
        numList.pop_back();
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector <int> numList;
    combination(numList, n, m);
    return 0;
}


