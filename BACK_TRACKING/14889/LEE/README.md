
# 백준 14889번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 01월 16일 23시 53분

---
### 메모리 및 시간

- 메모리 : 2016KB
- 시간 : 116ms

---

### 접근 방식
```cpp
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int minNum = 0;

int calculate(vector <vector<int>> &stat, vector <int> &stack) {
    int statNum = 0;
    for (int i = 0; i < stack.size(); i++) {
        for (int j = 0; j < stack.size(); j++) {
            statNum += stat[stack[i]][stack[j]];
        }
    }
    return statNum;
}

void dfs(vector <vector<int>> &stat, vector <bool> &visited,
         vector <int> &teamStack) {
    if (teamStack.size() == (stat.size() / 2)) {
        vector <int> anotherTeamStack;
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) anotherTeamStack.push_back(i);
        }
        int startTeam = calculate(stat, teamStack);
        int linkTeam = calculate(stat, anotherTeamStack);
        int diff = abs(startTeam - linkTeam);
        minNum = diff < minNum ? diff : minNum;
        return ;
    }
    int last = teamStack.size() ? teamStack.back() : -1;
    for (int i = 0; i < stat.size(); i++) {
        if (!visited[i] && i > last) {
            visited[i] = true;teamStack.push_back(i);
            dfs(stat, visited, teamStack);
            visited[i] = false; teamStack.pop_back();
        }
    }
    
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    vector <bool> visited(n, false);
    vector <int> teamStack;
    vector <vector <int>> stat(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> stat[i][j];
            minNum += stat[i][j];
        }
    }
    dfs(stat, visited, teamStack);
    cout << minNum << endl;
    return 0;
}





```




