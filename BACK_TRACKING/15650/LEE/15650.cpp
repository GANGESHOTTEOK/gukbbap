#include <iostream>
#include <vector>

#define FOR(i, n) for (int i = 0; i < n; i++)
using namespace std;

void combination(vector <bool> & visited, vector <int> & numList, int cnt) {
    if (numList.size() == cnt) { // 만약 출력할 숫자가 개수와 동일하다면
        FOR(i, numList.size()) cout << numList[i] + 1 << " ";
        cout << "\n";
        return ;
    }
    int last = numList.size() ? numList.back() : -1;
    
    FOR(i, visited.size()) {
        if (!visited[i] && i > last) {
            visited[i] = true;
            numList.push_back(i);
            combination(visited, numList, cnt);
            visited[i] = false;
            numList.pop_back();
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector <bool> visited(n, false); // 방문했는지 확인 할 벡터
    vector <int> numList; // 출력할 숫자들을 담을 벡터
    combination(visited, numList, m);
    return 0;
}


