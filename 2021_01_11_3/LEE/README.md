
# 백준 15649번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 01월 11일 14시 30분

---
### 메모리 및 시간

- 메모리 : 2016KB
- 시간 : 20ms

---

### 접근 방식
```cpp
#include <iostream>
#include <vector>
#define FOR(i, n) for (int i = 0; i < n; i++)
using namespace std;

void combination(vector <bool> & visited, vector <int> & numList, int cnt) {
    if (numList.size() == cnt) {
        FOR(i, numList.size()) cout << numList[i] + 1 << " ";
        cout << "\n";
        return ;
    }
    FOR(i, visited.size()) {
        if (!visited[i]) {
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
    vector <bool> visited(n, false);
    vector <int> numList;
    combination(visited, numList, m);
    return 0;
}


```
재귀함수를 이용해서 문제 해결.  




