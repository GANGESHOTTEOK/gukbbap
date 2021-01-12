
# 백준 15652번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 01월 12일 23시 45분

---
### 메모리 및 시간

- 메모리 : 2016KB
- 시간 : 4ms

---

### 접근 방식
```cpp
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
    
    int last = numList.size() ? numList.back() : -1;
    FOR(i, n) {
        if (i >= last) {
            numList.push_back(i);
            combination(numList, n, cnt);
            numList.pop_back();
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector <int> numList;
    combination(numList, n, m);
    return 0;
}




```
N과 M(1)을 응용해서 해결.




